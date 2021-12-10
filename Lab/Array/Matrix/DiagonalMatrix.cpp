#include <iostream>
using namespace std;

template <class T>
class DiagonalMatrix
{
    T *x;
    int size;

public:
    DiagonalMatrix(int size)
    {
        this->size = size;
        x = new int[size];
    }
    ~DiagonalMatrix()
    {
        delete[] x;
    }
    void setvalue(int i, int j, T value)
    {
        if (i < 1 || i > size || j < 1 || j > size)
        {
            throw "error!! Index out of Bound";
        }
        else if (i != j)
        {
            if (value != 0)
                throw "error!! diagonal matrix cannot have non-zero element at non-diagonal position";
        }
        else
        {
            *(x + i - 1) = value;
        }
    }

    T getvalue(int i, int j)
    {
        if (i < 1 || i > size || j < 1 || j > size)
        {
            throw "error!! Index out of Bound";
        }
        else if (i != j)
        {
            return 0;
        }
        else
        {
            return *(x + i - 1);
        }
    }
};

int main()
{
    cout << "\n--- Implementation of Diagonal Matrix ---\n" << endl;

    DiagonalMatrix<int> d1(4);

    try
    {
        d1.setvalue(1, 1, 10);
        d1.setvalue(2, 2, 20);
        d1.setvalue(3, 3, 30);
        d1.setvalue(4, 4, 40);
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    cout << "Diagonal Matrix :-" << endl;
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            cout << d1.getvalue(i, j) << " ";
        }
        cout << endl;
    }

	cout<<"\nChecking for some index not in list :-"<<endl;
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