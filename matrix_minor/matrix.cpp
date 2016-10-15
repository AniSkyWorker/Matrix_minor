#include "stdafx.h"
#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

size_t CMatrix::GetDimension() const
{
    return m_dimension;
}

MatrixType & CMatrix::GetMatrix()
{
    return m_matrix;
}

double CMatrix::GetDeterminant(MatrixType & matrix)
{
    double det = 1;
    for (size_t i = 0; i < matrix.size(); ++i)
    {
        size_t k = i;
        for (size_t j = i + 1; j < matrix.size(); ++j)
        {
            if (fabs(matrix[j][i]) > fabs(matrix[k][i]))
            {
                k = j;
            }
        }
        if (fabs(matrix[k][i]) < 1E-9)
        {
            return 0;
        }
        swap(matrix[i], matrix[k]);
        if (i != k)
        {
            det = -det;
        }


        det *= matrix[i][i];

        for (size_t j = i + 1; j < matrix.size(); ++j)
        {
            matrix[i][j] /= matrix[i][i];
        }
        for (size_t j = 0; j < matrix.size(); ++j)
        {
            if (j != i && fabs(matrix[j][i]) > 1E-9)
            {
                for (size_t k = i + 1; k < matrix.size(); ++k)
                {
                    matrix[j][k] -= matrix[i][k] * matrix[j][i];
                }
            }
        }
    }
    return det;
}