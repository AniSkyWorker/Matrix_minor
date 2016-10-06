#include "stdafx.h"
#include <algorithm>
#include "MatrixThreadedAgregator.h"

vector<unsigned> CMatrixThreadedAgregator::m_rang;
map<size_t, vector<size_t>> CMatrixThreadedAgregator::m_matrixQueue;

unsigned CMatrixThreadedAgregator::GetRang()
{
	vector<DWORD> dwThreadId(m_threadsCount);
	HANDLE *hTread = new HANDLE[m_threadsCount];
	vector<unsigned> threadTrigger;
	unsigned dimensionsPerThread = m_matrix.size() / m_threadsCount;
	for (size_t dimension = 1; dimension < m_matrix.size();dimension++)
	{
		unsigned thread = dimension - 1;
		vector<size_t> dimensions;
		dimensions.push_back(dimension);
		threadTrigger.push_back(thread);
		auto triggersPair = make_pair(thread, dimensions);
		m_matrixQueue.emplace(triggersPair);
	}

	for (size_t cur = 0, i = 0; cur < m_matrixQueue.size();)
	{
		if (i < m_threadsCount)
		{
			hTread[i] = CreateThread(NULL, 0, SubMatrix, (LPVOID)&threadTrigger[cur], 0, &dwThreadId[i]);
			i++;
			cur++;
		}
		else
		{
			WaitForMultipleObjects(m_threadsCount - 1, hTread, true, INFINITE);
			i = 0;
		}
	}

	WaitForMultipleObjects(m_threadsCount - 1, hTread, true, INFINITE);
	delete[] hTread;
	auto result = max_element(m_rang.begin(), m_rang.end());
	return result == m_rang.end() ? 0 : *result;
}

DWORD CMatrixThreadedAgregator::SubMatrix(LPVOID qParam)
{
	size_t p = (*((int*)qParam));
	auto q = m_matrixQueue[p];
	for (size_t i = 0; i < q.size(); i++)
	{
		Matrix Arr(q[i], vector<int>(q[i]));
		for (size_t a = 0;a < (MATRIX[0].size() - (q[i] - 1));a++)
		{
			for (size_t b = 0;b < (MATRIX.size() - (q[i] - 1));b++)
			{
				for (size_t c = 0;c < q[0];c++)
				{
					for (size_t d = 0;d < q[0];d++)
					{
						Arr[c][d] = MATRIX[a + c][b + d];
					}
				}

				if (GetDeterminant(Arr) != 0)
				{
					if (all_of(m_rang.begin(), m_rang.end(), [=](unsigned cur) { return cur != q[i];}))
					{
						m_rang.push_back(q[i]);
					}
				}
			}
		}
	}
	ExitThread(0);
	return 0;
}
