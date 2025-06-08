#ifndef MATRIX_H
#define MATRIX_H
#include "Calculator_mode.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Matrix : public Calculator_mode {
private:
    int choice;
    string modeName;
    vector<vector<double>> inputMatrix(int& rows, int& cols);
    void printMatrix(const vector<vector<double>>& matrix);

public:
    Matrix();
    virtual ~Matrix() = default;

    virtual void welcome() override;
    virtual void parse_operation(string const& str) override;
    virtual void print_name() override;
    virtual void set_choice(int choice) override;
    virtual int get_choice() override;

    void add();
    void subtract();
    void multiply();
    void transposeMatrix();
    double determinant(vector<vector<double>>& matrix);
    void calculateDeterminant();
    vector<vector<double>> inverse(vector<vector<double>>& m);
    void calculateInverse();
};

#endif