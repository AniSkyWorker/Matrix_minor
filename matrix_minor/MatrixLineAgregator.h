#pragma once
#include "MatrixAgregator.h"
class �MatrixLineAgregator : public CMatrixAgregator
{
public:
	�MatrixLineAgregator(const Matrix & matrix) : CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
};

