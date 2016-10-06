#pragma once
#include "MatrixAgregator.h"

class ÑMatrixLineAgregator : public CMatrixAgregator
{
public:
	ÑMatrixLineAgregator(const CMatrix & matrix) : CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
};

