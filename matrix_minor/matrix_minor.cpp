// matrix_minor.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <ctime>
#include "MatrixThreadedAgregator.h"
#include "MatrixLineAgregator.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		CMatrixThreadedAgregator mRangs(atoi(argv[1]), MATRIX);
		cout << mRangs.GetRang() << endl;
	}
	float first = float(clock());
	cout << first / CLOCKS_PER_SEC << endl;

	СMatrixLineAgregator mRang(MATRIX);
	cout << mRang.GetRang() << endl;
	cout << (float(clock()) - first) / CLOCKS_PER_SEC;
	return 0;
}

