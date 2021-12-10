#include <iostream>
using namespace std;

template <class T>
class TriDiagonalMatrix
{
    T *x;
    int n;

public:
    TriDiagonalMatrix(int n)
    {
        this->n = n;
        x = new int[3*n-2];
    }
    ~TriDiagonalMatrix()
    {
        delete[] x;
    }
    void setvalue(int i, int j, T value)
    {
        if (i < 1 || i > n || j < 1 || j > n)
            throw "error!! Index out of Bound";
        else if (i-j == 1)
            *(x + i - 2) = value;
        else if (i==j)
            *(x + n + i - 2) = value;
        else if (j-i == 1)
            *(x + 2*n + i - 2) = value;
		else
		{
			if(value != 0)
				throw "error! 0 expected rather than a non zero value";
		}		
    }

    T getvalue(int i, int j)
    {
        if (i < 1 || i > n || j < 1 || j > n)
            throw "error!! Index out of Bound";
        else if (i-j == 1)
            return *(x + i - 2);
        else if (i==j)
            return *(x + n + i - 2);
        else if (j-i == 1)
            return *(x + 2*n + i - 2);
		else
			return 0;
    }
};

int main()
{
    cout << "--- Implementation of TriDiagonal Matrix ---" << endl;

    TriDiagonalMatrix<int> d1(4);
    /*
         10   1   0  0
        100  20   2  0
          0 200  30  3
          0   0 300 40
    */
    try
    {
        d1.setvalue(1, 1, 10);
        d1.setvalue(2, 2, 20);
        d1.setvalue(3, 3, 30);
        d1.setvalue(4, 4, 40);
        d1.setvalue(1, 2, 1);
        d1.setvalue(2, 3, 2);
        d1.setvalue(3, 4, 3);
        d1.setvalue(2, 1, 100);
        d1.setvalue(3, 2, 200);
        d1.setvalue(4, 3, 300);
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    cout << "TriDiagonal Matrix :-" << endl;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << d1.getvalue(i, j) << " ";
        }
        cout << endl;
    }

    try
    {
        d1.getvalue(5, 5);
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    return 0;
}