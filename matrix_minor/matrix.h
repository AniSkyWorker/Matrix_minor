#pragma once
#include "TestMatrixData.h"

class CMatrix
{
public:
    CMatrix(const MatrixType & matrix) : m_matrix(matrix), m_dimension(matrix.size()) {}

    size_t GetDimension() const;

    MatrixType & GetMatrix();
    double GetDeterminant(MatrixType & matrix);
private:
    MatrixType m_matrix;
    size_t m_dimension;
};