#pragma once
#include "MatrixAgregator.h"

class CMatrixLineAgregator : public CMatrixAgregator
{
public:
	CMatrixLineAgregator(const CMatrix & matrix);

    unsigned GetRang() override;
};

