#include "stdafx.h"
#include "MatrixLineAgregator.h"

unsigned ÑMatrixLineAgregator::GetRang()
{
	size_t q = 1;
	unsigned r = 0;
	while (q <= m_matrix.size())
	{
		Matrix matrix(q, vector<int>(q));
		for (size_t a = 0;a < (m_matrix.size() - (q - 1));a++)
		{
			for (size_t b = 0;b < (m_matrix.size() - (q - 1));b++)
			{
				for (size_t c = 0;c<q;c++)
				{
					for (size_t d = 0;d<q;d++)
					{
						matrix[c][d] = m_matrix[a + c][b + d];
					}
				}

				if (GetDeterminant(matrix) != 0)
				{
					r = q;
				}
			}

		}
		q++;
	}
	return r;
}