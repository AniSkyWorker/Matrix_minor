#pragma once
#include "MatrixAgregator.h"
class ÑMatrixLineAgregator : public CMatrixAgregator
{
public:
	ÑMatrixLineAgregator(const Matrix & matrix) : CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
};

