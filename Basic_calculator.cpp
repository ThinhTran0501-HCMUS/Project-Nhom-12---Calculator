#include "Basic_calculator.h"
#include <iostream>
Basic_calculator::Basic_calculator(): ans(0.0), preans(0.0), mem(0.0){};

using namespace std;

Basic_calculator::Basic_calculator() : ans(0.0), preans(0.0), mem(0.0) {}

double Basic_calculator::parse_input(const string& input) {
    if (input == "pi" || input == "PI"|| input =="Pi") return PI;
    if (input == "e" || input == "E") return E;

    // Cố gắng chuyển thành số
     if (input == "ans")
    {
        return ans;
    }
    else if (input == "mem")
    {
        return mem;
    }
    else if(input == "preans")
    {
        return preans;
    }
    else
    {
        return std::stod(input);// chuyển về số
    }
    
}

void Basic_calculator::welcome() const {
    cout << "Welcome to Basic Calculator!\n"
    <<"         nhập các toán tử sau\n"
    <<"--------------------------------------\n"
    <<"   +   /    sin()     ln()\n"
    <<"   -   ^    cos()     lg()\n"
    <<"   x   v    tan()     abs()\n"
    <<"  ans preans  mem       =   \n"
    <<"--------------------------------------\n";    
}

// Hàm phân tách toán tử và lưu vào ans, preans (ví dụ: "3+4")
void Basic_calculator::parseOperation(const std::string& input) {
    if (input == "sin")
    {
        sin();
    }
    else if (input == "cos")
    {
        cos();
    }
    else if (input == "tan")
    {
        cos();
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
        pow();
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
        case '^': pow(); break;
        default: cerr << "Toán tử không xác định.\n"; break;
        }
    }
}

// Các phép tính
void Basic_calculator::add() {
    string a, b;
    cout << "Nhập số thứ nhất: ";cin >> a;
    cout << "Nhập số thứ 2: ";cin >> b;
    ans = parse_input(a) + parse_input(b);
    std::cout << ans;
}

void Basic_calculator::subtract() {
    string a, b;
    cout << "Nhập số thứ nhất: ";cin >> a;
    cout << "Nhập số thứ 2: ";cin >> b;
    ans = parse_input(a) - parse_input(b);
    std::cout  << ans;
}

void Basic_calculator::multiply() {
    string a, b;
    cout << "Nhập số thứ nhất: ";cin >> a;
    cout << "Nhập số thứ 2: ";cin >> b;
    ans = parse_input(a) * parse_input(b);
    std::cout  << ans;
}

void Basic_calculator::divide() {
   string a, b;
    cout << "Nhập số thứ nhất: ";cin >> a;
    cout << "Nhập số thứ 2: ";cin >> b;
    ans = parse_input(a) / parse_input(b);
    std::cout  << ans;
}

void Basic_calculator::square() {
    string a;
    cout << "Nhập số : ";cin >> a;
    ans = parse_input(a) * parse_input(a);
    std::cout  << ans;
}

void Basic_calculator::sqrt() {
    string a;
    cout << "Nhập số : ";cin >> a;
    if (parse_input(a) < 0) {
        cerr << "Lỗi không nhập số âm.\n";//có thể thêm hàm phức
        return;
    }
    ans = std::sqrt(parse_input(a));
    cout  << ans << endl;
}

// Các hàm lượng giác (giả định đầu vào là độ, convert trước)
void Basic_calculator::conver_angle() {
    string a;
    cout << "Nhập số : ";cin >> a;
    ans=parse_input(a)* PI / 180.0;
    
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
    std::cout << "Nhập một số: ";
    std::cin >> a;
    ans = std::log(parse_input(a));
    std::cout  << ans;
}

void Basic_calculator::log() {
    string a,b;
    std::cout << "Nhập một số ";
    std::cin >> a;
    cout<<"nhập cơ số: ";
    cin>>b;
    ans = std::log(parse_input(b))/ std::log(parse_input(a));
    std::cout  << ans;
}

void Basic_calculator::abs() {
    string a;
    std::cout<<"Nhập một số: ";cin>>a;
    ans = std::fabs(ans);
    cout  << ans << endl;
}

void Basic_calculator::pow() {
    string a,b;
    std::cout<<"Nhập số: ";cin>>a;
    std::cout<<"mũ: ";cin>>b;
    ans = std::pow(parse_input(a), parse_input(b));
    cout  << ans << endl;
}

// Bộ nhớ
void Basic_calculator::set_mem() {
    std::cout<<"Biến 'nhớ' lưu là: ";
    std::cin>>mem;
    cout <<"mem= " << mem << endl;
}

void Basic_calculator::print_mem() const {
    cout << "mem:= " << mem << endl;
}


