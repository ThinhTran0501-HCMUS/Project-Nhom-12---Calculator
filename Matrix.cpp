#include"Matrix.h"
#include<iostream>
#include<string>
using namespace std;
Matrix::~Matrix(){}
Matrix::Matrix(){}
vector<vector<double>> Matrix::inputMatrix(int& rows, int& cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<double>> matrix(rows,vector<double>(cols));
    std::cout << "Enter elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    return matrix;
}
void Matrix::printMatrix(vector<vector<double>>& matrix){
    cout << "Result matrix:\n";
    for (vector<double> row : matrix) {
        for (double val : row)
            cout << val << "\t";
        cout << "\n";
    }
}
void Matrix::add(){
    int rows1, cols1, rows2, cols2;
    cout << "--- Matrix Addition ---\n";

    // Gọi inputMatrix và khai báo kiểu rõ ràng
    vector<vector<double>> mat1 = inputMatrix(rows1, cols1);
    vector<vector<double>> mat2 = inputMatrix(rows2, cols2);

    if (rows1 != rows2 || cols1 != cols2) {
        cout << "Matrix dimensions do not match!\n";
        return;
    }

    // Tạo ma trận kết quả
    vector<vector<double>> result(rows1,vector<double>(cols1));

    // Tính tổng
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols1; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // In kết quả
    printMatrix(result);
}
void Matrix::subtract(){
    int r1, c1, r2, c2;
    vector<vector<double>> m1 = inputMatrix(r1, c1);
    vector<vector<double>> m2 = inputMatrix(r2, c2);
    if (r1 != r2 || c1 != c2) {
        cout << "Matrix sizes do not match for subtraction.\n";
        return;
    }
    vector<vector<double>> result(r1, vector<double>(c1));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            result[i][j] = m1[i][j] - m2[i][j];
    cout << "Result of subtraction:\n";
    printMatrix(result);
}
void Matrix::multiply(){
     int r1, c1, r2, c2;
    vector<vector<double>> m1 = inputMatrix(r1, c1);
    vector<vector<double>> m2 = inputMatrix(r2, c2);
    if (c1 != r2) {
        cout << "Invalid dimensions for multiplication.\n";
        return;
    }
    vector<vector<double>> result(r1, vector<double>(c2, 0));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            for (int k = 0; k < c1; ++k)
                result[i][j] += m1[i][k] * m2[k][j];
    cout << "Result of multiplication:\n";
    printMatrix(result);
}
void Matrix::transposeMatrix(){
    int r, c;
    auto m = inputMatrix(r, c);
    vector<vector<double>> result(c, vector<double>(r));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[j][i] = m[i][j];
    cout << "Transposed matrix:\n";
    printMatrix(result);
}
double Matrix::determinant(vector<vector<double>>& matrix){
     int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

    double det = 0;
    for (int p = 0; p < n; ++p) {
        vector<vector<double>> subMatrix(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            int colIndex = 0;
            for (int j = 0; j < n; ++j) {
                if (j == p) continue;
                subMatrix[i - 1][colIndex++] = matrix[i][j];
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * determinant(subMatrix);
    }
    return det;
}
void Matrix::calculateDeterminant(){
     int r, c;
    auto m = inputMatrix(r, c);
    if (r != c) {
        cout << "Matrix must be square to compute determinant.\n";
        return;
    }
    cout << "Determinant: " << determinant(m) << endl;
}
vector<vector<double>> Matrix::inverse(vector<vector<double>>& m) {
    int n = m.size();
    vector<vector<double>> aug(n, vector<double>(2 * n));

    // Create augmented matrix [A|I]
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) aug[i][j] = m[i][j];
        aug[i][i + n] = 1;
    }

    // Gauss-Jordan elimination
    for (int i = 0; i < n; ++i) {
        if (aug[i][i] == 0) {
            bool found = false;
            for (int j = i + 1; j < n; ++j) {
                if (aug[j][i] != 0) {
                    swap(aug[i], aug[j]);
                    found = true;
                    break;
                }
            }
            if (!found) throw runtime_error("Matrix is singular.");
        }

        double diag = aug[i][i];
        for (int j = 0; j < 2 * n; ++j)
            aug[i][j] /= diag;

        for (int k = 0; k < n; ++k) {
            if (k == i) continue;
            double factor = aug[k][i];
            for (int j = 0; j < 2 * n; ++j)
                aug[k][j] -= factor * aug[i][j];
        }
    }

    vector<vector<double>> inv(n, vector<double>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            inv[i][j] = aug[i][j + n];
    return inv;
}

void Matrix::calculateInverse() {
    int r, c;
    auto m = inputMatrix(r, c);
    if (r != c) {
        cout << "Matrix must be square to compute inverse.\n";
        return;
    }
    try {
        vector<vector<double>> inv = inverse(m);
        cout << "Inverse matrix:\n";
        printMatrix(inv);
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}

