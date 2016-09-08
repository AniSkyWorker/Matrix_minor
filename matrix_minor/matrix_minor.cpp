// matrix_minor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
typedef vector<vector<int>> matrix;

namespace {
	const matrix MATRIX =
	{
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 },
		{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32 },
		{ 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48 },
		{ 4, 8, 12, 16, 20, 24, 28, 32, 36, 40, 44, 48, 52, 56, 60, 64 },
		{ 5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80 },
		{ 6, 12, 18, 24, 30, 36, 42, 48, 54, 60, 66, 72, 78, 84, 90, 96 },
		{ 7, 14, 21, 28, 35, 42, 49, 56, 63, 70, 77, 84, 91, 98, 105, 112 },
		{ 8, 16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128 },
		{ 9, 18, 27, 36, 45, 54, 63, 72, 81, 90, 99, 108, 117, 126, 135, 144 },
		{ 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160 },
		{ 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 132, 143, 154, 165, 176 },
		{ 12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 156, 168, 180, 192 },
		{ 13, 26, 39, 52, 65, 78, 91, 104, 117, 130, 143, 156, 169, 182, 195, 208 },
		{ 14, 28, 42, 56, 70, 84, 98, 112, 126, 140, 154, 168, 182, 196, 210, 224 },
		{ 15, 30, 45, 60, 75, 90, 105, 120, 135, 150, 165, 180, 195, 210, 225, 240 },
		{ 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 240, 256 },
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

	void PrintMatrix(const matrix & mtrx)
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
int _tmain(int argc, _TCHAR* argv[])
{
	GenerateInitVectorListToFile(16);
	PrintMatrix(MATRIX);
	return 0;
}

