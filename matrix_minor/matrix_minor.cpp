#include "stdafx.h"
#include "MatrixThreadedAgregator.h"
#include "MatrixLineAgregator.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        CMatrixThreadedAgregator threadedAgreagator(MATRIX);
        threadedAgreagator.SetThreadsCount(atoi(argv[1]));
        cout << threadedAgreagator.GetRang() << endl;
    }
    float first = float(clock());
    cout << first / CLOCKS_PER_SEC << endl;

    CMatrixLineAgregator lineAgregator(MATRIX);
    cout << lineAgregator.GetRang() << endl;
    cout << (float(clock()) - first) / CLOCKS_PER_SEC;
    return 0;
}

