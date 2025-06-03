#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>	//Su dung cho cac ham nhap xuat trong C, neu khong co thu vien nay se khong the dung scanf, printf
#include <stdlib.h> //dung cho  atoi (chuyen doi chuoi thanh so nguyen)
#include <string.h> // dung cho cac thao tac trong chuoi
#include <math.h> //dung cho cac ham toan hoc fabs abs
#include <stdexcept>
#include "polynomial_cal.h"

using namespace std;

int Polynomial_mode(){

    Polynomial dt1, dt2;
    Polynomial dt_result;
    int opt;

    cout<<"Michaelsoft Binbows [Version 10.0.69420.4090]"<<endl;
    cout<<endl;
    cout<<"  >>> KAL-1000 Polynomial Calculator <<<"<<endl;
    cout<<"Copyright (C) Michaelsoft Corporation. All rights reserved.\n"<<endl;
    cout<<"Install the latest Calculator for new features and improvements! https://youtu.be/dQw4w9WgXcQ"<<endl;
    cout<<endl;

    cout<<"Enter first polynomial:";
    dt1.nhap_dt();
    dt1.rut_gon_dt();
    cout<<"Enter second polynomial:";
    dt2.nhap_dt();
    dt2.rut_gon_dt();

    while(true){
            cout<<"Choose operation:\n";
            cout<<"\t1. Sum\n";
            cout<<"\t2. Difference\n";
            cout<<"\t3. Product\n";
            cout<<"\t4. Quotient\n";
            cout<<"\t5. i wanna go home\n";
            cout<<"\tEnter your choice (1-5): ";
            cin >> opt;      
        switch (opt)
        {
        case 1:{ 
            dt_result = dt1.cong_dt(dt2);
            break;}
        case 2:{ 
            dt_result = dt1.tru_dt(dt2);
            break;}
        case 3:{ 
            dt_result = dt1.nhan_dt(dt2);
            break;}
        case 4:{ 
            dt_result = dt1.chia_dt(dt2);
            break;}
        case 5:{ 
            cout<<"See you next time!";
            return 0;}
        default:
            cout<<"Invalid selection!\n\n";
            break;
        }       
        cout<<"Resulting polynomial: ";
        dt_result.print(); 
    }
    return 0;
}


int main(){
    Polynomial_mode();
    return 0;
}