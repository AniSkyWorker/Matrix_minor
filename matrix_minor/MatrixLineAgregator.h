#pragma once
#include "MatrixAgregator.h"

class �MatrixLineAgregator : public CMatrixAgregator
{
public:
	�MatrixLineAgregator(const CMatrix & matrix) : CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
};

