#include "stdafx.h"
#include <ctime>
#include "MatrixThreadedAgregator.h"
#include "MatrixLineAgregator.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc == 2)
	{
		CMatrixThreadedAgregator threadedAgreagator(atoi(argv[1]), MATRIX);

		cout << threadedAgreagator.GetRang() << endl;
	}
	float first = float(clock());
	cout << first / CLOCKS_PER_SEC << endl;

	ÑMatrixLineAgregator lineAgregator(MATRIX);
	cout << lineAgregator.GetRang() << endl;
	cout << (float(clock()) - first)/ CLOCKS_PER_SEC;
	return 0;
}

