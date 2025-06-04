#ifndef BASIC_CALCULATOR_H
#define BASIC_CALCULATOR_H

#include <cmath>
#include <array>
#include <string>
#include <iostream>
//kế thừa calculator mode
// #include "Calculator_mode.h"
const double PI = 3.14159265358979323846;
const double E  = 2.71828182845904523536;
using namespace std;
class Basic_calculator{
    protected:
    double ans, preans, mem;
    public:
    Basic_calculator();//cho ans, preans, mem = 0.0
    virtual ~Basic_calculator() =default;//hàm destructor mặc định hủy 

    // ---- hàm tính toán đều nhập từ 2 số ,đang học vector dự kiến t7 cn chỉnh sửa hàm phân giải input và toán tử//
    //hàm nhập input nếu là e thì define nếu pi là 3.14 đầu vào 
    virtual double parse_input(const string&);

    // Giới thiệu (overrive)
    virtual void welcome() const;

    //hàm phân tách dấu (ở th nhập vào 2 biến)
    virtual void parseOperation(const std::string&);

    //các hàm tính toán
    void add();             
    void subtract();
    void multiply();
    void divide();
    void square();
    void sqrt();

    //các hàm sciencetific
    void conver_angle();
    void sin();
    void cos();
    void tan();
    void ln();
    void log();
    void abs();
    void pow();

    //hàm đặt biến 'nhớ'
    void set_mem();
    void print_mem() const;

    

};


#endif