#include <iostream>
#include <string>
#include "Combination.h"

using namespace std;

int main() {
    Combination combi;
    combi.welcome();

    string command;

    while (true) {
        cout << "\n Enter (combi, arrange, perm, print_mem, set_mem, exit): ";
        cin >> command;

        if (command == "exit") {
            cout << "Exit the program.\n"; // command=exit thì thoát chương trình 
            break;
        }
        else if (command == "combi") { // tổ hợp có dạng nCr
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            combi.combi_cal(n, r);
        }
        else if (command == "arrange") {  // chỉnh hợp có dạng nAr 
            int n, r;
            cout << "Enter n and r: ";
            cin >> n >> r;
            combi.arrangement(n, r);
        }
        else if (command == "perm") { // hoán vị n!
            int n;
            cout << "Enter n: ";
            cin >> n;
            combi.permutation(n);
        }
        else if (command == "print_mem" || command == "set_mem") { // in giá trị bộ nhớ và kết quả nó đã lưu 
            combi.parseOperation(command);
        }
        else {
            cout << "not valid.\n";
        }
    }

    return 0;
}
