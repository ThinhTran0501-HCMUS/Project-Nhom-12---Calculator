#include "Basic_calculator.h"
#include <iostream>
#include <cmath>
#include <array>
#include <string>

using namespace std;

Basic_calculator::Basic_calculator() : ans(0.0), preans(0.0), mem(0.0) {}

double Basic_calculator::parse_input(const string& str) {
    // Lowercase input for easier comparison
    string in;
    for (char c : str)
        in += tolower(c);

    // Named constants
    if (in == "pi") return PI;
    if (in == "e")  return E;

    // Word to number map
    if (in == "zero")  return 0;
    if (in == "one")   return 1;
    if (in == "two")   return 2;
    if (in == "three") return 3;
    if (in == "four")  return 4;
    if (in == "five")  return 5;
    if (in == "six")   return 6;
    if (in == "seven") return 7;
    if (in == "eight") return 8;
    if (in == "nine")  return 9;
        // Cố gắng chuyển thành số
     if (in == "ans")
    {
        return ans;
    }
    else if (in == "mem")
    {
        return mem;
    }
    else if(in == "preans")
    {
        return preans;
    } 
    // Try to parse number
    try {
        return stod(str);
    } catch (...) {
        cerr << "Invalid input: " << str << ". Defaulting to 0.\n";
        return 0.0;
    }   
}

void Basic_calculator::welcome() const {
    cout << "BASIC CALCULATOR MODE\n"
    <<"         Enter your input\n"
    <<"--------------------------------------\n"
    <<"   +   /    sin()     ln()\n"
    <<"   -   ^    cos()     lg()\n"
    <<"   x   sqrt    tan()     abs()\n"
    <<"  ans preans  mem       =    exit\n"
    <<"--------------------------------------\n";    
}

// Hàm phân tách toán tử và lưu vào ans, preans (ví dụ: "3+4")
void Basic_calculator::parseOperation(const string& input) {
    if (input == "sin")
    {
        sin();
    }
    else if (input=="sqrt"){
        sqroot();
    }
    else if (input == "cos")
    {
        cos();
    }
    else if (input == "tan")
    {
        tan();
    }
    else if (input == "ln")
    {
        ln();
    }
    else if (input == "log")
    {
        log();
    }
    else if (input == "abs")
    {
        abs();
    }
    else if (input == "pow")
    {
        power();
    }
    else if (input == "setmem")
    {
        set_mem();
    }
    else if (input == "printmem")
    {
        print_mem();
    }
    else 
    {
        char(input);
        switch (input) 
        {
        case '+': add(); break;
        case '-': subtract(); break;
        case '*': multiply(); break;
        case '/': divide(); break;
        case '^': power(); break;
        default: cerr << "Invalid operator\n"; break;
        }
    }
}

// Các phép tính
void Basic_calculator::add() {
    string a, b;
    cout << "Enter first number: ";cin >> a;
    cout << "Enter second number: ";cin >> b;
    preans=ans;
    ans = parse_input(a) + parse_input(b);
    cout << ans;
}

void Basic_calculator::subtract() {
    string a, b;
    cout<< "Enter first number: ";cin >> a;
    cout <<"Enter second number: ";cin >> b;
    preans=ans;
    ans = parse_input(a) - parse_input(b);
    cout  << ans;
}

void Basic_calculator::multiply() {
    string a, b;
    cout << "Enter first number: ";cin >> a;
    cout << "Enter second number: ";cin >> b;
    preans=ans;
    ans = parse_input(a) * parse_input(b);
    cout  << ans;
}

void Basic_calculator::divide() {
   string a, b;
    cout << "Enter first number: ";cin >> a;
    cout << "Enter second number: ";cin >> b;
    if (parse_input(b)!=0){
    preans=ans;
    ans = parse_input(a) / parse_input(b);
    cout  << ans;
    }
    else{
        cout<<"\n Can not divided by 0\n";
    }
}

void Basic_calculator::square() {
    string a;
    cout << "Enter a number: ";cin >> a;
    preans=ans;
    ans = parse_input(a) * parse_input(a);
    cout  << ans;
}

void Basic_calculator::sqroot() {
    string a;
    cout << "Enter a number: ";cin >> a;
    if (parse_input(a) < 0) {
        cerr << "Math Error!.\n";//có thể thêm hàm phức
        return;
    }
    ans = sqrt(parse_input(a));
    cout  << ans << endl;
}

// Các hàm lượng giác (giả định đầu vào là độ, convert trước)
void Basic_calculator::conver_angle() {
    string a;
    cout << "Enter a number: ";cin >> a;
    ans=(parse_input(a)* PI) / 180.0;
    
}

void Basic_calculator::sin() {
    conver_angle();
    ans = std::sin(ans);
    cout  << ans << endl;
}

void Basic_calculator::cos() {
    conver_angle();
    ans = std::cos(ans);
    cout << ans << endl;
}

void Basic_calculator::tan() {
    conver_angle();
    ans = std::tan(ans);
    cout  << ans << endl;
}

void Basic_calculator::ln() {
    std::string a;
    std::cout << "Enter a number: ";
    std::cin >> a;
    ans = std::log(parse_input(a));
    std::cout  << ans;
}

void Basic_calculator::log() {
    string a,b;
    std::cout << "Enter a number: ";
    std::cin >> a;
    cout<<"Base:  ";
    cin>>b;
    ans = std::log(parse_input(b))/ std::log(parse_input(a));
    std::cout  << ans;
}

void Basic_calculator::abs() {
    string a;
    cout << "Enter a number: ";cin >> a;
    preans=ans;
    ans = std::abs(ans);
    cout  << ans << endl;
}

void Basic_calculator::power() {
    string a,b;
    cout << "Enter the number: ";cin >> a;
    std::cout<<"Exponet: ";cin>>b;
    preans=ans;
    ans = pow(parse_input(a), parse_input(b));
    cout  << ans << endl;
}

// Bộ nhớ
void Basic_calculator::set_mem() {
    std::cout<<"Set mem: ";
    std::cin>>mem;
    cout <<"mem= " << mem << endl;
}

void Basic_calculator::print_mem() const {
    cout << "mem= " << mem << endl;
}


