#include "iteration.h"
#include <cmath>

double* iteration(double** matrix, double* ind, int iterations, int precision, int rows, int columns) {
    double* current = new double[columns];
    for (int i = 0; i < columns; i++)
    {
        current[i] = 0;
    }
    double* previous = new double[columns];
    for (int i = 1; i <= iterations; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            previous[j] = current[j];
        }
        for (int k = 0; k < rows; k++)
        {
            double sum = 0;
            for (int l = 0; l < k; l++)
            {
                sum += (matrix[k][l] * current[l]);
            }
            for (int n = k + 1; n < columns; n++)
            {
                sum += (matrix[k][n] * previous[n]);


            }
            current[k] = round(((ind[k] - sum) / matrix[k][k] * pow(10, precision))) / pow(10, precision);
        }
    }
    return(current);
}