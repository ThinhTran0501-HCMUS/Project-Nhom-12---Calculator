#ifndef MATRIX_H
#define MATRIX_H
#include"calculator.h"
using namespace std;
#include<iostream>
#include<string>
#include<vector>
class Matrix:public Calculator {
    public:
    Matrix();
    ~Matrix();
    void add();
    void inputMatrix();
    void displayMatrix();
    void subtract();
    void multiply();
    void welcome();
    void parseOperation(string&);
    void transposeMatrix();
    double determinant(vector<vector<double>>& matrix);
    void calculateDeterminant();
    vector<vector<double>>inverse(vector<vector<double>>& m);
    void calculateInverse();
    private:
    vector<vector<double>> inputMatrix(int& rows, int& cols);
    void printMatrix(vector<vector<double>>& matrix);
};
#endif