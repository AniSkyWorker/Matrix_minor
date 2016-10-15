#pragma once
#include "MatrixAgregator.h"

class CMatrixThreadedAgregator : public CMatrixAgregator
{
public:
    CMatrixThreadedAgregator(const CMatrix & matrix);

    unsigned GetRang() override;
    void SetThreadsCount(unsigned threadsCount);

private:
    static DWORD WINAPI GetSubMatrixRangCalculationResult(LPVOID qParam);

    static std::vector<unsigned> m_rang;
    unsigned m_threadsCount;
};
