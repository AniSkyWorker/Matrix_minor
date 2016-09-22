// matrix_minor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <Windows.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>


using namespace std;
typedef vector<vector<int>> matrix;

namespace
{
	const matrix MATRIX =
	{ { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 },
	{ 2, 20, 6, 8, 10, 12, 14, 16, 18, 20 },
	{ 3, 30, 9, 12, 15, 18, 21, 24, 27, 30 },
	{ 4, 8, 12, 16, 20, 24, 28, 32, 36, 40 },
	{ 5, 400, 122, 20, 25, 30, 35, 40, 45, 50 },
	{ 6, 12, 18, 24, 30, 36, 42, 48, 54, 60 },
	{ 7, 14, 21, 28, 35, 42, 49, 56, 63, 70 },
	{ 8, 32, 24, 32, 40, 48, 56, 64, 72, 80 },
	{ 9, 18, 27, 36, 45, 54, 63, 72, 81, 90 },
	{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 }
	};

	void GenerateInitVectorListToFile(int dimension)
	{
		ofstream out;
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

	void PrintMatrix(matrix mtrx)
	{
		ofstream out;
		out.open("result.txt");
		auto dimension = mtrx.size();
		for (size_t i = 0; i < mtrx.size(); i++)
		{
			out << "{";
			for (size_t j = 0; j < mtrx.size(); j++)
			{
				out << mtrx[i][j];
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
}

class MatrixRang
{
public:
	int GetMatrixRang()
	{
		int q = 1;
		int r = 0;
		while (q <= MATRIX.size())
		{
			matrix Arr(q, vector<int>(q));
			for (int a = 0;a<(MATRIX.size() - (q - 1));a++)
			{
				for (int b = 0;b<(MATRIX.size() - (q - 1));b++)
				{
					for (int c = 0;c<q;c++)
					{
						for (int d = 0;d<q;d++)
						{
							Arr[c][d] = MATRIX[a + c][b + d];
						}
					}

					if (!(determ(Arr, q) == 0))
					{
						r = q;
					}
				}
				
			}
			q++;
		}
		return r;
	}
	double determ(const matrix & Arr, size_t size)
	{
		int i, j;
		double det = 0;
		if (size == 1)
		{
			det = Arr[0][0];
		}
		else if (size == 2)
		{
			det = Arr[0][0] * Arr[1][1] - Arr[0][1] * Arr[1][0];
		}
		else
		{
			matrix matr(size - 1, vector<int>(size - 1));
			for (i = 0;i < size;++i)
			{
				for (j = 0;j < size - 1;++j)
				{
					if (j < i)
						matr[j] = Arr[j];
					else
						matr[j] = Arr[j + 1];
				}
				det += pow((double)-1, (i + j))*determ(matr, size - 1)*Arr[i][Arr.size() - 1];
			}
		}
		return det;
	}
};


int main(int argc, char* argv[])
{
	MatrixRang mRang;
	std::cout << mRang.GetMatrixRang();
	return 0;
}

