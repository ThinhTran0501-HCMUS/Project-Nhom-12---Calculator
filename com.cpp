#include <iostream>
#include <string>
#include "Combination.h"

using namespace std;

int main() {
    Combination combi;
    combi.welcome();

    string command;

    while (true) {
        cout << "\nNhập lệnh (combi, arrange, perm, print_mem, set_mem, exit): ";
        cin >> command;

        if (command == "exit") {
            cout << "Thoát chương trình.\n";
            break;
        }
        else if (command == "combi") {
            int n, r;
            cout << "Nhập n và r: ";
            cin >> n >> r;
            combi.combi_cal(n, r);
        }
        else if (command == "arrange") {
            int n, r;
            cout << "Nhập n và r: ";
            cin >> n >> r;
            combi.arrangement(n, r);
        }
        else if (command == "perm") {
            int n;
            cout << "Nhập n: ";
            cin >> n;
            combi.permutation(n);
        }
        else if (command == "print_mem" || command == "set_mem") {
            combi.parseOperation(command);
        }
        else {
            cout << "Lệnh không hợp lệ.\n";
        }
    }

    return 0;
}
