#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>	//Su dung cho cac ham nhap xuat trong C, neu khong co thu vien nay se khong the dung scanf, printf
#include <stdlib.h> //dung cho  atoi (chuyen doi chuoi thanh so nguyen)
#include <string.h> // dung cho cac thao tac trong chuoi
#include <math.h> //dung cho cac ham toan hoc fabs abs
#include "POLYNOMIAL_CAL.H"
using namespace std;

#define max 50

Polynomial::Polynomial(){
    for (int i = 0; i < max; ++i) {
        coeffs[i] = 0;
        fcoeffs[i] = 0.0f;
        /*note: coeffs la he so nguyen da thuc. 
        vd  3x^2−2x+5: coeffs[2]=3, coeffs[1]=-2, coeffs[0]=5  + */
    }
    degree = 0;
    dt[0] = '\0';

}

Polynomial::~Polynomial(){} //good practice with destructor

void Polynomial::nhap_dt(){ //dua vao scope cua Polynomial va gia su co ham bo tro, se phan biet ham bo tro va lop Polynomial 
    cin.getline(dt, max);
}

void Polynomial::rut_gon_dt(){
    //reset
    for (int i = 0; i < max; ++i) {
            coeffs[i] = 0; 
        }
        int len = strlen(dt);
        int sign = 1, stack[max], top = 0;
        stack[0] = 1;

        for (int i = 0; i < len; ) {
            if (dt[i] == ' ') { ++i; continue; }
            if (dt[i] == '+') {
                sign = stack[top];
                ++i;
            }
            else if (dt[i] == '-') {
                sign = -stack[top];
                ++i;
            }
            else if (dt[i] == '(') {
                stack[++top] = sign;
                ++i;
            }
            else if (dt[i] == ')') {
                --top;
                ++i;
            }
            else {
                // đọc một hạng tử
                char temp[32] = {0};
                int j = 0;
                while (i < len && dt[i]!='+' && dt[i]!='-' && dt[i]!='(' && dt[i]!=')') {
                    temp[j++] = dt[i++];
                }
                temp[j] = '\0';

                // tìm 'x'
                char* px = strchr(temp, 'x');
                int heso = 0, bac = 0;
                if (px) {
                    // he so
                    if (px == temp) heso = 1;
                    else {
                        *px = '\0';
                        heso = atoi(temp);
                    }
                    // bac
                    if (*(px+1) == '^') bac = std::atoi(px+2);
                    else bac = 1;
                } else {
                    heso = std::atoi(temp);
                    bac = 0;
                }
                if (bac < max) {
                    coeffs[bac] += heso * sign;
                }
            }
        }

        // tính bậc
        degree = 0;
        for (int i = max-1; i >= 0; --i) {
            if (coeffs[i] != 0) {
                degree = i;
                break;
            }
        }
}


int Polynomial::lay_bac() const {
    return degree;
}

Polynomial Polynomial::cong_dt(Polynomial daThuc){
    int max_exp = (this->lay_bac() >= daThuc.lay_bac()) ? this->lay_bac() : daThuc.lay_bac();
    Polynomial res;
    for (int i = 0; i <= max_exp; ++i) {
        res.coeffs[i] = this->coeffs[i] + daThuc.coeffs[i];
    }
    // cập nhật degree
    for (int i = max-1; i >= 0; --i) {
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    }
    return res;
} 

Polynomial Polynomial::tru_dt(Polynomial daThuc){
    Polynomial res;
    int max_exp = (this->lay_bac() >= daThuc.lay_bac()) ? this->lay_bac() : daThuc.lay_bac();
    for (int i = 0; i <= max_exp; ++i) {
        res.coeffs[i] = this->coeffs[i] - daThuc.coeffs[i];
    }
    for (int i = max-1; i >= 0; --i) {
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    }
    return res;
}

Polynomial Polynomial::nhan_dt(Polynomial daThuc){
     Polynomial res;
    for (int i = 0; i <= degree; ++i) {
        for (int j = 0; j <= daThuc.degree; ++j) {
            if (i + j < max)
                res.coeffs[i+j] += this->coeffs[i] * daThuc.coeffs[j];
        }
    }
    for (int i = max-1; i >= 0; --i) {
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    }
    return res;
}

Polynomial Polynomial::chia_dt(Polynomial daThuc){
    Polynomial res;
    // copy hệ số sang fcoeffs để chia
    for (int i = 0; i <= degree; ++i) fcoeffs[i] = coeffs[i];
    for (int i = 0; i <= daThuc.degree; ++i) daThuc.fcoeffs[i] = daThuc.coeffs[i];

    int rem_deg = degree;
    float rem[max];
    memcpy(rem, fcoeffs, sizeof(rem));

    while (rem_deg >= daThuc.degree) {
        int d = rem_deg - daThuc.degree;
        float coef = rem[rem_deg] / daThuc.fcoeffs[daThuc.degree];
        res.fcoeffs[d] = coef;
        // trừ phần nhân
        for (int j = 0; j <= daThuc.degree; ++j) {
            rem[d+j] -= coef * daThuc.fcoeffs[j];
        }
        // cập nhật rem_deg
        while (rem_deg>0 && fabs(rem[rem_deg]) < 1e-6) --rem_deg;
    }
    // copy thương float về hệ số nguyên (làm tròn)
    for (int i = 0; i < max; ++i) {
        res.coeffs[i] = round(res.fcoeffs[i]);
    }
    // cập nhật degree của thương
    for (int i = max-1; i >= 0; --i) {
        if (res.coeffs[i] != 0) { res.degree = i; break; }
    }
    return res;
}

void Polynomial::print() const {
    bool first = true;
    for (int i = degree; i >= 0; --i) {
        int c = coeffs[i];
        if (c == 0) continue;
        if (!first) {
            cout << (c>0 ? " + " : " - ");
        } else if (c < 0) {
            cout << "-";
        }
        int ac = abs(c);
        if (ac != 1 || i == 0) cout << ac;
        if (i > 0) {
            cout << "x";
            if (i > 1) cout << "^" << i;
        }
        first = false;
    }
    if (first) cout << "0";  // đa thức bằng 0
    cout << "\n";
}