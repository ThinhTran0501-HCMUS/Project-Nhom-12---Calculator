#include "Base_of_N_convert.h"
#include <stdexcept>

Base::Base() : choice(1), modeName("Base-N Converter") {}

void Base::welcome() {
    cout << "\nBASE-N CONVERTER\n";
    cout << "Choose the base of your input number:\n";
    cout << "  1. Binary (BIN)\n";
    cout << "  2. Octal  (OCT)\n";
    cout << "  3. Decimal(DEC)\n";
    cout << "  4. Hex    (HEX)\n";
    cout << "  5. Exit to Main Menu\n";
}

void Base::print_name() {
    cout << "\nMode: " << modeName << endl;
}

void Base::set_choice(int choice) {
    this->choice = choice;
}

int Base::get_choice() {
    return choice;
}

void Base::parse_operation(const string& str) {
    while (true) {
        welcome();
        cout << "\nEnter your choice (1-5): ";
        int subChoice;
        cin >> subChoice;
        set_choice(subChoice);

        if (subChoice == 5) {
            cout << "Returning to main menu...\n";
            break;
        }

        try {
            int decimal = 0;

            switch (subChoice) {
                case 1: setBin(); decimal = To_Dec(input, 2); break;
                case 2: setOct(); decimal = To_Dec(input, 8); break;
                case 3: setDec(); decimal = stoi(input); break;
                case 4: setHex(); decimal = To_Dec(input, 16); break;
                default:
                    cout << "Invalid choice. Try again.\n";
                    continue;
            }

            dec = to_string(decimal);
            bin = To_BaseOfN(decimal, 2);
            oct = To_BaseOfN(decimal, 8);
            hex = To_BaseOfN(decimal, 16);

            cout << "\n=== CONVERSION RESULT ===\n";
            display();
            cout << endl;

        } catch (const exception& e) {
            cout << "Exception: " << e.what() << "\n";
        }
    }
}

void Base::display() {
    cout << "BIN: " << bin << endl;
    cout << "DEC: " << dec << endl;
    cout << "OCT: " << oct << endl;
    cout << "HEX: " << hex << endl;
}

bool Base::isValidForBase(const string& input, int base) {
    for (char c : input) {
        c = toupper(c);
        const char* pos = strchr(digit, c);
        if (!pos) return false;
        int val = pos - digit;
        if (val >= base) return false;
    }
    return true;
}

void Base::setBin() {
    cout << "BIN: ";
    cin.ignore();
    getline(cin, input);
    if (!isValidForBase(input, 2))
        throw invalid_argument("Invalid binary number.");
    bin = input;
}

void Base::setOct() {
    cout << "OCT: ";
    cin.ignore();
    getline(cin, input);
    if (!isValidForBase(input, 8))
        throw invalid_argument("Invalid octal number.");
    oct = input;
}

void Base::setDec() {
    cout << "DEC: ";
    cin.ignore();
    getline(cin, input);
    if (!isValidForBase(input, 10))
        throw invalid_argument("Invalid decimal number.");
    dec = input;
}

void Base::setHex() {
    cout << "HEX: ";
    cin.ignore();
    getline(cin, input);
    if (!isValidForBase(input, 16))
        throw invalid_argument("Invalid hexadecimal number.");
    hex = input;
}

int Base::To_Dec(string input, int base) {
    int result = 0, power = 1;
    for (int i = input.length() - 1; i >= 0; i--) {
        char ch = toupper(input[i]);
        int value = (ch >= '0' && ch <= '9') ? ch - '0' : ch - 'A' + 10;
        result += value * power;
        power *= base;
    }
    return result;
}

string Base::To_BaseOfN(int number, int base) {
    if (number == 0) return "0";
    string result = "";
    while (number > 0) {
        result = digit[number % base] + result;
        number /= base;
    }
    return result;
}