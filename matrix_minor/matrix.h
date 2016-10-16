#pragma once
#include "TestMatrixData.h"
#include <boost/optional.hpp>

class CMatrix
{
public:
    CMatrix(const MatrixType & matrix) : m_matrix(matrix) {}

    size_t GetDimension();

    MatrixType & GetMatrix();
    double GetDeterminant(MatrixType & matrix);
private:
    MatrixType m_matrix;
    boost::optional<size_t> m_dimension;
};