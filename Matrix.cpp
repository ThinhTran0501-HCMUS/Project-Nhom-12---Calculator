#include "Matrix.h"

Matrix::Matrix() : choice(1), modeName("Matrix Calculator") {}

void Matrix::welcome() {
    cout << "\n MATRIX CALCULATOR\n";
    cout << "Choose a matrix operation:\n\n";
    cout << "  1. Add Matrices\n";
    cout << "  2. Subtract Matrices\n";
    cout << "  3. Multiply Matrices\n";
    cout << "  4. Transpose Matrix\n";
    cout << "  5. Determinant\n";
    cout << "  6. Inverse\n";
    cout << "  7. Exit to Main Menu\n";
}

void Matrix::print_name() {
    cout << "\nMode: " << modeName << endl;
}

void Matrix::set_choice(int choice) {
    this->choice = choice;
}

int Matrix::get_choice() {
    return choice;
}

void Matrix::parse_operation(const string& str) {
    while (true) {
        welcome();
        cout << "\nEnter operation number (1-7): ";
        int subChoice;
        cin >> subChoice;
        set_choice(subChoice);
        if (subChoice == 7) {
            cout << "Returning to main menu...\n";
            break;
        }

        switch (subChoice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: transposeMatrix(); break;
            case 5: calculateDeterminant(); break;
            case 6: calculateInverse(); break;
            default: cout << "Invalid choice.\n"; continue;
        }

        cout << endl;
    }
}

vector<vector<double>> Matrix::inputMatrix(int& rows, int& cols) {
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    vector<vector<double>> matrix(rows, vector<double>(cols));
    cout << "Enter elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j) {
            cout << "[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }

    return matrix;
}

void Matrix::printMatrix(const vector<vector<double>>& matrix) {
    cout << "Matrix:\n";
    for (const auto& row : matrix) {
        for (double val : row)
            cout << val << "\t";
        cout << "\n";
    }
}

void Matrix::add() {
    cout << "--- Matrix Addition ---\n";
    int r1, c1, r2, c2;
    auto m1 = inputMatrix(r1, c1);
    auto m2 = inputMatrix(r2, c2);
    if (r1 != r2 || c1 != c2) {
        cout << "Matrices must be the same size.\n";
        return;
    }
    vector<vector<double>> result(r1, vector<double>(c1));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            result[i][j] = m1[i][j] + m2[i][j];
    printMatrix(result);
}

void Matrix::subtract() {
    cout << "--- Matrix Subtraction ---\n";
    int r1, c1, r2, c2;
    auto m1 = inputMatrix(r1, c1);
    auto m2 = inputMatrix(r2, c2);
    if (r1 != r2 || c1 != c2) {
        cout << "Matrices must be the same size.\n";
        return;
    }
    vector<vector<double>> result(r1, vector<double>(c1));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            result[i][j] = m1[i][j] - m2[i][j];
    printMatrix(result);
}

void Matrix::multiply() {
    cout << "--- Matrix Multiplication ---\n";
    int r1, c1, r2, c2;
    auto m1 = inputMatrix(r1, c1);
    auto m2 = inputMatrix(r2, c2);
    if (c1 != r2) {
        cout << "Columns of first matrix must equal rows of second.\n";
        return;
    }
    vector<vector<double>> result(r1, vector<double>(c2, 0));
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            for (int k = 0; k < c1; ++k)
                result[i][j] += m1[i][k] * m2[k][j];
    printMatrix(result);
}

void Matrix::transposeMatrix() {
    cout << "--- Transpose Matrix ---\n";
    int r, c;
    auto m = inputMatrix(r, c);
    vector<vector<double>> result(c, vector<double>(r));
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            result[j][i] = m[i][j];
    printMatrix(result);
}

double Matrix::determinant(vector<vector<double>>& matrix) {
    int n = matrix.size();
    if (n == 1) return matrix[0][0];
    if (n == 2) return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0];

    double det = 0;
    for (int p = 0; p < n; ++p) {
        vector<vector<double>> sub(n - 1, vector<double>(n - 1));
        for (int i = 1; i < n; ++i) {
            int colIdx = 0;
            for (int j = 0; j < n; ++j) {
                if (j == p) continue;
                sub[i - 1][colIdx++] = matrix[i][j];
            }
        }
        det += (p % 2 == 0 ? 1 : -1) * matrix[0][p] * determinant(sub);
    }
    return det;
}

void Matrix::calculateDeterminant() {
    cout << "--- Calculate Determinant ---\n";
    int r, c;
    auto m = inputMatrix(r, c);
    if (r != c) {
        cout << "Matrix must be square.\n";
        return;
    }
    cout << "Determinant: " << determinant(m) << endl;
}

vector<vector<double>> Matrix::inverse(vector<vector<double>>& m) {
    int n = m.size();
    vector<vector<double>> aug(n, vector<double>(2 * n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) aug[i][j] = m[i][j];
        aug[i][i + n] = 1;
    }

    for (int i = 0; i < n; ++i) {
        if (aug[i][i] == 0) {
            for (int j = i + 1; j < n; ++j) {
                if (aug[j][i] != 0) {
                    swap(aug[i], aug[j]);
                    break;
                }
            }
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
    cout << "--- Calculate Inverse ---\n";
    int r, c;
    auto m = inputMatrix(r, c);
    if (r != c) {
        cout << "Matrix must be square.\n";
        return;
    }
    try {
        auto inv = inverse(m);
        printMatrix(inv);
    } catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }
}