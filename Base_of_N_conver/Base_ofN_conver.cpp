#include "Base_of_N_conver.h"

Base::Base(int choice){
     int decimal = 0;
        switch (choice) {
            case 1: // Binary
                setBin();
                decimal = To_Dec(input, 2);
                break;
            case 3: // Decimal
                setDec();
                decimal = stoi(input); // chỉ dùng stoi cho hệ 10
                break;
            case 2: // Octal
                setOct();
                decimal = To_Dec(input, 8);
                break;
            case 4: // Hex
                setHex();
                decimal = To_Dec(input, 16);
                break;
            default:
                throw invalid_argument("Invalid choice in Base constructor.");
        }

        dec = to_string(decimal);
        bin = To_BaseOfN(decimal, 2);
        oct = To_BaseOfN(decimal, 8);
        hex = To_BaseOfN(decimal, 16);
    }
    

//10 -> bất kỳ
string Base::To_BaseOfN(int number, int base){
        
        string result = "";
        if (number==0) return "0";
        while (number > 0) {
            int r = number % base;
            result = digit[r] + result;
            number /= base;
        }
    

        return result == "" ? "0" : result;
}

int Base::To_Dec(string input, int base){
        int result = 0;
        int power = 1;

        for (int i = input.length() - 1; i >= 0; i--) {
            char ch = toupper(input[i]);
            int value = (ch >= '0' && ch <= '9') ? ch - '0' : ch - 'A' + 10;
            result += value * power;
            power *= base;
        }
        return result;
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

//hàm đặt 
void Base::setBin(){
    
        cout<<"0 1"
        <<"\n^==^\n"
        <<"BIN: ";

    cin.ignore();
    getline(cin,input);
    if(!isValidForBase(input,2)){
        throw invalid_argument("invalid number: the number must in base!");
    }

    bin=input;
    

}

void Base::setOct(){
 
    cout<<"  0\n1 2 3\n4 5 6\n  7"
        <<"\n^=====^\n"
        <<"---:\nOCT: ";

    cin.ignore();
    getline(cin,input);
    if(!isValidForBase(input,8)){
        throw invalid_argument("invalid number: the number must in base!");
    }
    oct=input;
    
}

void Base::setDec(){
    
    cout<<"  0\n1 2 3\n4 5 6\n7 8 9 "
        <<"\n^=====^\n"
        <<"---:\n---:\nDEC: ";

    cin.ignore();
    getline(cin,input);
    if(!isValidForBase(input,10)){
        throw invalid_argument("Invalid number: the number must in the base");
    }
    dec=input;
    
}

void Base::setHex(){
    
    cout<<"  0\n1 2 3\n4 5 6\n7 8 9\nA B C\nD E F"
        <<"\n^=====^\n"
        <<"---:\n---:\n---:\nHEX: ";

    cin.ignore();
    getline(cin,input);
    if(!isValidForBase(input,16)){
        throw invalid_argument("Invalid number: the number must in the base");
    }
    hex=input;
}

void Base::display(){
        cout << "BIN: " << bin << endl;
        cout << "DEC: " << dec << endl;
        cout << "OCT: " << oct << endl;
        cout << "HEX: " << hex << endl;
    }
