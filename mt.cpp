#include <iostream>
#include "Matrix.h"

using namespace std;

int main() {
    Matrix matrixCalc;
    int choice;

    do {
        cout << "\n===== MATRIX CALCULATOR =====\n";
        cout << "1. Add Matrices\n";
        cout << "2. Subtract Matrices\n";
        cout << "3. Multiply Matrices\n";
        cout << "4. Transpose Matrix\n";
        cout << "5. Calculate Determinant\n";
        cout << "6. Calculate Inverse\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Xử lý làm sạch bộ nhớ đệm nhập nếu nhập không hợp lệ
        if (cin.fail()) {
            cin.clear(); // xóa cờ lỗi
            cin.ignore(10000, '\n'); // bỏ qua input sai
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                matrixCalc.add();
                break;
            case 2:
                matrixCalc.subtract();
                break;
            case 3:
                matrixCalc.multiply();
                break;
            case 4:
                matrixCalc.transposeMatrix();
                break;
            case 5:
                matrixCalc.calculateDeterminant();
                break;
            case 6:
                matrixCalc.calculateInverse();
                break;
            case 0:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);

    return 0;
}
