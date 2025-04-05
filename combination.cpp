#include<iostream>
#include<math.h>
using namespace std;

class Calculator{
    public:
    long long factorial(int n);
    long long combination(int n ,int k);
    long long arrangement(int n, int k);

};
    long long Calculator::factorial(int n){ // hàm tinh giai thua cua n phan tu 
        if(n=0){
            return 1;
        }
        else {
            return n*factorial(n-1);
        }
    }
    long long Calculator::combination(int n, int k){ // ham tinh to hop chap k cua n phan tu 
        if(n>1 && n>k && k>0){
            return factorial(n)/(factorial(k)*factorial(n-k));
        }
        else{
            cout << "error" <<endl;
        }
    }
    long long Calculator::arrangement(int n, int k){ // ham tinh chinh hop chap k cua n phan tu
        if(n>1 && n>k && k>0){
            return factorial(n)/(factorial(n-k));
        }
        else {
            cout << "error" <<endl;
        }
    }
    int main(){
        Calculator hv_th_ch;
        int n;
        int k;
        int option;
        cout <<" entered n elements "<<endl;
        cin>>n;
        cout<<" entered k elements "<<endl;
        cin>>k;
        cout << "\n option :\n";
        cout << "1. combination (C)\n";
        cout << "2. arrangement (A)\n";
        cin>>option;
        cout << "--------------------------\n";
        switch (option) {
            case 1:
                cout << "combination C(" << n << ", " << k << ") = " << hv_th_ch.combination(n, k) << endl;
                break;
            case 2:
                cout << "arrangement A(" << n << ", " << k << ") = " << hv_th_ch.arrangement(n, k) << endl;
                break;
            default:
                cout << "error!\n";
                break;
        }
        return 0;
    }
