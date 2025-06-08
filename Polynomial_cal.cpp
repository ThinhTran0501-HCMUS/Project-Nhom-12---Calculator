#include "Polynomial_cal.h"
#include <cstdlib>
#include <stdexcept>
#include <cmath>
#include <cstring>

Polynomial::Polynomial() : degree(0), choice(1), modeName("Polynomial Simplification") {
    memset(coeffs, 0, sizeof(coeffs));
    memset(fcoeffs, 0, sizeof(fcoeffs));
    dt[0] = '\0';
}

Polynomial::~Polynomial() {}

void Polynomial::welcome() {
    cout << "\nPOLYNOMIAL CALCULATOR\n";
    cout << "Enter two polynomials and choose an operation:\n";
}

void Polynomial::print_name() {
    cout << "\nMode: " << modeName << endl;
}

void Polynomial::set_choice(int choice) {
    this->choice = choice;
}

int Polynomial::get_choice() {
    return this->choice;
}

void Polynomial::parse_operation(const string& str) {
    Polynomial dt1, dt2, dt_result;

    cout << "Enter first polynomial: ";
    cin.ignore();
    dt1.nhap_dt();
    dt1.rut_gon_dt();

    cout << "Enter second polynomial: ";
    dt2.nhap_dt();
    dt2.rut_gon_dt();

    while (true) {
        cout << "\nChoose operation:\n";
        cout << "  1. Sum\n";
        cout << "  2. Difference\n";
        cout << "  3. Product\n";
        cout << "  4. Quotient\n";
        cout << "  5. Return to Main Menu\n";
        cout << "Enter choice (1-5): ";
        int opt;
        cin >> opt;
        set_choice(opt);

        switch (opt) {
            case 1: dt_result = dt1.cong_dt(dt2); break;
            case 2: dt_result = dt1.tru_dt(dt2); break;
            case 3: dt_result = dt1.nhan_dt(dt2); break;
            case 4: dt_result = dt1.chia_dt(dt2); break;
            case 5:
                cout << "Returning to main menu...\n";
                return;
            default:
                cout << "Invalid selection!\n";
                continue;
        }

        cout << "Resulting polynomial: ";
        dt_result.print();
    }
}

void Polynomial::nhap_dt() {
    cin.getline(dt, maximum);
}

void Polynomial::rut_gon_dt() {
    memset(coeffs, 0, sizeof(coeffs));
    int len = strlen(dt), sign = 1, stack[maximum], top = 0;
    stack[0] = 1;

    for (int i = 0; i < len;) {
        if (dt[i] == ' ') { ++i; continue; }
        if (dt[i] == '+') { sign = stack[top]; ++i; }
        else if (dt[i] == '-') { sign = -stack[top]; ++i; }
        else if (dt[i] == '(') { stack[++top] = sign; ++i; }
        else if (dt[i] == ')') { --top; ++i; }
        else {
            char temp[32] = {0};
            int j = 0;
            while (i < len && dt[i] != '+' && dt[i] != '-' && dt[i] != '(' && dt[i] != ')') {
                temp[j++] = dt[i++];
            }
            temp[j] = '\0';

            char* px = strchr(temp, 'x');
            int heso = 0, bac = 0;
            if (px) {
                if (px == temp) heso = 1;
                else { *px = '\0'; heso = atoi(temp); }
                bac = (*(px + 1) == '^') ? atoi(px + 2) : 1;
            } else {
                heso = atoi(temp); bac = 0;
            }

            if (bac < maximum) coeffs[bac] += heso * sign;
        }
    }

    degree = 0;
    for (int i = maximum - 1; i >= 0; --i)
        if (coeffs[i] != 0) { degree = i; break; }
}

int Polynomial::lay_bac() const {
    return degree;
}

Polynomial Polynomial::cong_dt(Polynomial other) {
    Polynomial res;
    int max_exp = max(lay_bac(), other.lay_bac());
    for (int i = 0; i <= max_exp; ++i)
        res.coeffs[i] = coeffs[i] + other.coeffs[i];
    for (int i = maximum - 1; i >= 0; --i)
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    return res;
}

Polynomial Polynomial::tru_dt(Polynomial other) {
    Polynomial res;
    int max_exp = max(lay_bac(), other.lay_bac());
    for (int i = 0; i <= max_exp; ++i)
        res.coeffs[i] = coeffs[i] - other.coeffs[i];
    for (int i = maximum - 1; i >= 0; --i)
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    return res;
}

Polynomial Polynomial::nhan_dt(Polynomial other) {
    Polynomial res;
    for (int i = 0; i <= degree; ++i)
        for (int j = 0; j <= other.degree; ++j)
            if (i + j < maximum)
                res.coeffs[i + j] += coeffs[i] * other.coeffs[j];
    for (int i = maximum - 1; i >= 0; --i)
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    return res;
}

Polynomial Polynomial::chia_dt(Polynomial other) {
    Polynomial res;
    for (int i = 0; i <= degree; ++i) fcoeffs[i] = coeffs[i];
    for (int i = 0; i <= other.degree; ++i) other.fcoeffs[i] = other.coeffs[i];

    int rem_deg = degree;
    float rem[maximum]; memcpy(rem, fcoeffs, sizeof(rem));

    while (rem_deg >= other.degree) {
        int d = rem_deg - other.degree;
        float coef = rem[rem_deg] / other.fcoeffs[other.degree];
        res.fcoeffs[d] = coef;

        for (int j = 0; j <= other.degree; ++j)
            rem[d + j] -= coef * other.fcoeffs[j];

        while (rem_deg > 0 && fabs(rem[rem_deg]) < 1e-6) --rem_deg;
    }

    for (int i = 0; i < maximum; ++i)
        res.coeffs[i] = round(res.fcoeffs[i]);
    for (int i = maximum - 1; i >= 0; --i)
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    return res;
}

void Polynomial::print() const {
    bool first = true;
    for (int i = degree; i >= 0; --i) {
        int c = coeffs[i];
        if (c == 0) continue;
        if (!first) cout << (c > 0 ? " + " : " - ");
        else if (c < 0) cout << "-";

        int ac = abs(c);
        if (ac != 1 || i == 0) cout << ac;
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
        first = false;
    }
    if (first) cout << "0";
    cout << "\n";
}