#include<cmath>
#include<iostream>
using namespace std;
const double pi=3.141592653589793;

double Equation_solve::quadratic_delta(double a,double b, double c){
    if(a!=0){
        return (b*b-4*a*c);
    }
    else{
        return 0;
    }
}

double Equation_solve::quadratic_solving(double a, double b, double c){
    if (a==0&&b==0&&c==0){
        cout<<"The equation has inf roots"<<endl;
    }
    else if (a==0&&b==0&&c!=0){
        cout<<"The equation has no roots"<<endl;
    }
    else if (a==0&&b!=0&&c!=0){
        double quadratic_root=(-c/b);
        cout<<"x = "<<quadratic_root<<endl;
    }
    else{
        double delta=quadratic_delta(a,b,c);
        if(delta==0){
            double quadratic_root=(-b/(2*a));
            cout<<"x = "<<quadratic_root<<endl;
        }
        else if(delta>0){
            double quadratic_root_1=((-b+sqrt(delta))/(2*a));
            double quadratic_root_2=((-b-sqrt(delta))/(2*a));
            cout<<"x1 = "<<quadratic_root_1<<"; "<<"x2 = "<<quadratic_root_2<<endl;
        }
        else{
            double root_real_part=(-b/(2*a));
            double root_imagi_part=(sqrt(-delta)/2*a);
            cout<<"x1 = "<<root_real_part<<" + "<<root_imagi_part<<"*i ; "<<"x2 = "<<root_real_part<<" - "<<root_imagi_part<<"*i"<<endl;
        }
    }
}

double Equation_solve::cbroot_imagine_theta(double real, double imagin){
    double agumen=sqrt(real*real-imagin*imagin);
    double r=cbrt(agumen);
    double theta;
    if((imagin/agumen)>=0){
        theta=acos(real/agumen);
    }
    else if(((imagin/agumen)<0) && ((real/agumen)>=0)){
        theta=asin(imagin/agumen);
    }
    else{
        theta=(2*asin(imagin/agumen)-pi);
    }
    return theta;
}

double Equation_solve::cbroot_imagine(double real, double imagine, double theta){
double omega1=theta/3;
double omega2=theta/3+2*pi/3;
double omega3=theta/3+4*pi/3;
double
}

double Equation_solve::cubic_solving(double a, double b, double c, double d){
    if(a==0){
        quadratic_solving(b,c,d);
    }
    else{
        double delta1 = (b*c/(6*a*a)-d/(2*a)-b*b*b/(27*a*a*a));
        double delta2 = delta1*delta1+(c/(3*a)-b*b/(9*a*a))*(c/(3*a)-b*b/(9*a*a))*(c/(3*a)-b*b/(9*a*a));
        if(delta2>=0){
            cout<<"x = "<<cbrt(delta1+sqrt(delta2))+cbrt(delta1-sqrt(delta2)-b/(3*a))<<endl;
        }
        else{
            ...
        } 
    }
}
