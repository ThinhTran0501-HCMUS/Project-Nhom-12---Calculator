#include <iostream>
#include <string>
#include <stdio.h>	//Su dung cho cac ham nhap xuat trong C, neu khong co thu vien nay se khong the dung scanf, printf
#include <stdlib.h> //dung cho  atoi (chuyen doi chuoi thanh so nguyen)
#include <string.h> // dung cho cac thao tac trong chuoi
#include <math.h> //dung cho cac ham toan hoc fabs abs
#define max 50
#ifndef POLYNOMIAL_CAL_H
#define POLYNOMIAL_CAL_H
using namespace std;

class Polynomial{
    private:
    char dt[max]; // chuoi da thuc
    int coeffs[max]; //he so nguyen sau rut gon
    float fcoeffs[max];
    int degree; //bac da thuc


    
    public:
    Polynomial();
    virtual ~Polynomial(); //good practice, tao xong xoa luon
    //void welcome();
    void nhap_dt();
    void rut_gon_dt(); //chuyen tu dt[] thanh coeffs[] va tinh degree
    int lay_bac() const; //tra ve bac da thuc
    Polynomial cong_dt(Polynomial daThuc); //anon obj
    //dt3 = dt1 + dt2 --- 2 thang dt nay se cong voi nhau tra ve obj la Polynomial dt khac
    //dt3 la 1 object co tat ca thuoc tinh, thay vi chi la 1 mang char[]
    //dt.cong_dt(daThuc) ==== dt + daThuc
    //ham nay se lay cai dt cua private cua Polynomial dt + dt cua private cua Polynomial daThuc 
    Polynomial tru_dt(Polynomial daThuc); 
    Polynomial nhan_dt(Polynomial daThuc);
    Polynomial chia_dt(Polynomial daThuc); 
    void print() const;
};
#endif

/*moi method nhu cong, tru, nhan, chia se:
+ tao obj ket qua
+ tu 0 -> max, tinh ket qua da thuc
+ goi result lay bac ----> result degree
+ tra ve result
*/