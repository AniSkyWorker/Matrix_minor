#pragma once
#include "MatrixAgregator.h"
#include <map>
#include <Windows.h>

class CMatrixThreadedAgregator : public CMatrixAgregator
{
public:
	CMatrixThreadedAgregator(unsigned threadsCount, const Matrix & matrix) : m_threadsCount(threadsCount), CMatrixAgregator(matrix) {}

	unsigned GetRang() override;
	static DWORD WINAPI SubMatrix(LPVOID qParam);

	static vector<unsigned> m_rang;
	static map<size_t, vector<size_t>> m_matrixQueue;
private:
	unsigned m_threadsCount;
};
