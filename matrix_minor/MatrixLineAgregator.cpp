#include "stdafx.h"
#include "MatrixLineAgregator.h"

using namespace std;

CMatrixLineAgregator::CMatrixLineAgregator(const CMatrix & matrix) : CMatrixAgregator(matrix) {}

unsigned CMatrixLineAgregator::GetRang()
{
    size_t currentDimension = 1;
    size_t matrixDimension = m_matrix.GetDimension();
    unsigned rang = 0;
    while (currentDimension <= matrixDimension)
    {
        MatrixType matrix(currentDimension, vector<int>(currentDimension));
        for (size_t i = 0; i < (matrixDimension - (currentDimension - 1)); i++)
        {
            for (size_t j = 0; j < (matrixDimension - (currentDimension - 1)); j++)
            {
                for (size_t i1 = 0; i1 < currentDimension; i1++)
                {
                    for (size_t j1 = 0; j1 < currentDimension; j1++)
                    {
                        matrix[i1][j1] = m_matrix.GetMatrix()[i + i1][j + j1];
                    }
                }

                if (m_matrix.GetDeterminant(matrix) != 0)
                {
                    rang = currentDimension;
                }
            }

        }
        currentDimension++;
    }
    return rang;
}