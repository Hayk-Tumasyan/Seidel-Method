#include <iostream>
#include <iomanip>
#include <cmath>
#include "iteration.h"
using namespace std;

int main()
{
    int rows, columns;
    cout << "Enter how many rows and how many unknowns your system of equations has: ";
    cin >> rows >> columns;
    while (rows != columns)
    {
        cout << "To implement the Seidel's method you need equal quantity of rows and unknowns. Please enter valid values: ";
        cin >> rows >> columns;
    }

    double* ind = new double[rows];
    double** matrix = new double* [rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new double[columns+1];
    }

    for (int i = 0; i < rows; i++)
    {
        
        for (int j = 0; j < columns; j++) {
            cout << "Enter the value of " << j + 1 << " coefficient of the " << i + 1 << " equation: ";
            cin >> matrix[i][j];
            cout << "\n";
        }
            cout << "Enter the value of the independent term: ";
            cin >> ind[i];
    }

    int iters;
    int precision;
    cout << "\n" << "\nHow many iterations?: ";
    cin >> iters;
    cout << "\n" << "Precision(decimal places): ";
    cin >> precision;
    double* result = iteration(matrix, ind, iters, precision, rows, columns);

    cout << "The result:" << "\n\n";
    for (int i = 0; i < columns; i++)
    {
        cout << result[i] << setw(10);
    }

    cin.ignore();
    cin.get();

    return 0;

}

