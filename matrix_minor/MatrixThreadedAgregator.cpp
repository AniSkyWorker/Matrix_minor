#include "stdafx.h"
#include <algorithm>
#include "MatrixThreadedAgregator.h"
#include <Windows.h>

using namespace std;
typedef std::pair<CMatrix*, unsigned> dimensionPair;

vector<unsigned> CMatrixThreadedAgregator::m_rang;

unsigned CMatrixThreadedAgregator::GetRang()
{
	vector<DWORD> dwThreadId(m_threadsCount);
	HANDLE *hTread = new HANDLE[m_threadsCount];
	vector<dimensionPair> threadTrigger;
	for (unsigned dimension = 1; dimension < m_matrix.GetDimension(); dimension++)
	{
		threadTrigger.emplace_back(make_pair(&m_matrix, dimension));
	}

	for (size_t triggerIndex = 0, currentThreadCount = 0; triggerIndex < m_matrix.GetDimension();)
	{
		if (currentThreadCount < m_threadsCount)
		{
			hTread[currentThreadCount] = CreateThread(NULL, 0, SubMatrix, (LPVOID)&threadTrigger[triggerIndex], 0, &dwThreadId[currentThreadCount]);
			currentThreadCount++;
			triggerIndex++;
		}
		else
		{
			WaitForMultipleObjects(m_threadsCount, hTread, true, INFINITE);
			currentThreadCount = 0;
		}
	}

	WaitForMultipleObjects(m_threadsCount, hTread, true, INFINITE);
	delete[] hTread;
	auto result = max_element(m_rang.begin(), m_rang.end());
	return result == m_rang.end() ? 0 : *result;
}

DWORD CMatrixThreadedAgregator::SubMatrix(LPVOID qParam)
{
	dimensionPair pair = *((dimensionPair*)qParam);
	if (pair.first != nullptr)
	{
		CMatrix baseMatrix = *(pair.first);
		unsigned dimension = pair.second;
		MatrixType subMatrix(dimension, vector<int>(dimension));
		for (size_t i = 0; i < (baseMatrix.GetDimension() - (dimension - 1)); i++)
		{
			for (size_t j = 0; j < (baseMatrix.GetDimension() - (dimension - 1)); j++)
			{
				for (size_t i1 = 0; i1 < dimension; i1++)
				{
					for (size_t j1 = 0; j1 < dimension; j1++)
					{
						subMatrix[i1][j1] = baseMatrix.GetMatrix()[i + i1][j + j1];
					}
				}

				if (baseMatrix.GetDeterminant(subMatrix) != 0)
				{
					if (all_of(m_rang.begin(), m_rang.end(), [=](unsigned cur) { return cur != dimension;}))
					{
						m_rang.push_back(dimension);
					}
				}
			}
		}
	}
	ExitThread(0);
	return 0;
}
