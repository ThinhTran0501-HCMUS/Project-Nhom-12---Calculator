#include <iostream>
#include <cmath>
#include <complex>

using namespace std;
const double pi=3.141592653589793;
double quadratic_delta(double a,double b, double c){
    if(a!=0){
        return (b*b-4*a*c);
    }
    else{
        return 0;
    }
}

void quadratic_solving(double a, double b, double c){
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

int main(){
    double a,b,c;
    cout<<"Nhap a, b, c"<<endl;
    cin>>a>>b>>c;
    quadratic_solving(a,b,c);
    return 0;
}