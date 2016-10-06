#pragma once
#include "matrix.h"

class CMatrixAgregator
{
public:
	CMatrixAgregator(const Matrix & matrix) : m_matrix(matrix) {}
	virtual unsigned GetRang() = 0;
protected:

	Matrix m_matrix;
};