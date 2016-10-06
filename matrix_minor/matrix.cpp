#include "stdafx.h"
#include "matrix.h"
#include <iostream>
#include <fstream>

using namespace std;

namespace
{
	void GenerateInitVectorListToFile(int dimension)
	{
		std::ofstream out;
		out.open("1.txt");
		for (auto i = 1; i < dimension + 1; i++)
		{
			out << "{";
			for (auto j = 1; j < dimension + 1; j++)
			{
				out << i * j;
				if (j != dimension)
				{
					out << ", ";
				}
			}
			out << "}";
			if (i != dimension)
			{
				out << "," << endl;
			}
		}

		out.close();
	}
}

size_t CMatrix::GetDimension() const
{
	return m_matrix.size();
}

MatrixType & CMatrix::GetMatrix()
{
	return m_matrix;
}

void CMatrix::PrintMatrix() const
{
	ofstream out;
	out.open("result.txt");
	auto dimension = m_matrix.size();
	for (size_t i = 0; i < m_matrix.size(); i++)
	{
		out << "{";
		for (size_t j = 0; j < m_matrix.size(); j++)
		{
			out << m_matrix[i][j];
			if (j != dimension - 1)
			{
				out << ", ";
			}
		}
		out << "}";
		if (i != dimension - 1)
		{
			out << "," << endl;
		}
	}

	out.close();
}

double CMatrix::GetDeterminant(MatrixType & matrix)
{
	double det = 1;
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		size_t k = i;
		for (size_t j = i + 1; j < matrix.size(); ++j)
		{
			if (fabs(matrix[j][i]) > fabs(matrix[k][i]))
			{
				k = j;
			}
		}
		if (fabs(matrix[k][i]) < 1E-9)
		{
			return 0;
		}
		swap(matrix[i], matrix[k]);
		if (i != k)
		{
			det = -det;
		}


		det *= matrix[i][i];

		for (size_t j = i + 1; j < matrix.size(); ++j)
		{
			matrix[i][j] /= matrix[i][i];
		}
		for (size_t j = 0; j < matrix.size(); ++j)
		{
			if (j != i && fabs(matrix[j][i]) > 1E-9)
			{
				for (size_t k = i + 1; k < matrix.size(); ++k)
				{
					matrix[j][k] -= matrix[i][k] * matrix[j][i];
				}
			}
		}
	}
	return det;
}