#pragma once
#include "MatrixAgregator.h"

class CMatrixThreadedAgregator : public CMatrixAgregator
{
public:
	CMatrixThreadedAgregator(unsigned threadsCount, const CMatrix & matrix) : m_threadsCount(threadsCount), CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
	static DWORD WINAPI SubMatrix(LPVOID qParam);

	static std::vector<unsigned> m_rang;
private:
	unsigned m_threadsCount;
};
