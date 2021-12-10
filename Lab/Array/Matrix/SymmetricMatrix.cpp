#include <iostream>
using namespace std;

template <class T>
class UpTriMatrix
{
    T *x;
    int n;

public:
    UpTriMatrix(int n)
    {
        this->n = n;
        x = new int[n*(n+1)/2];
    }
    ~UpTriMatrix()
    {
        delete[] x;
    }
    void setvalue(int i, int j, T value)
    {
        if (i < 1 || i > n || j < 1 || j > n)
            throw "error!! Index out of Bound";
        else if (j>=i)
		{
			// row major using only upper triangular elements
			*(x + n*(i-1) - (i-1)*(i-2)/2 + j-i ) = value;
		}
		else
		{
			*(x + n*(j-1) - (j-1)*(j-2)/2 + i-j ) = value;	
		}		
    }

    T getvalue(int i, int j)
    {
        if (i < 1 || i > n || j < 1 || j > n)
            throw "error!! Index out of Bound";
        else if (j>=i)
		{
			return *(x + n*(i-1) - (i-1)*(i-2)/2 + j-i );
		}
		else
		{
			return *(x + n*(j-1) - (j-1)*(j-2)/2 + i-j );
		}
    }
};

int main()
{
    cout << "\n--- Implementation of Symmetric Matrix ---\n" << endl;
	int n = 5;
    UpTriMatrix<int> d1(5);
    /*
        7 4 7 9 7
		4 1 5 8 8
        7 5 2 6 4
        9 8 6 3 5
		7 8 4 5 2
    */
    try
    {
        d1.setvalue(1, 1, 7);
        d1.setvalue(2, 2, 1);
        d1.setvalue(3, 3, 2);
        d1.setvalue(4, 4, 3);
        d1.setvalue(2, 1, 4);
        d1.setvalue(2, 3, 5);
        d1.setvalue(3, 4, 6);
        d1.setvalue(1, 3, 7);
        d1.setvalue(3, 4, 6);
		d1.setvalue(4, 2, 8);
        d1.setvalue(1, 4, 9);
		d1.setvalue(5, 5, 2);
		d1.setvalue(4, 5, 5);
		d1.setvalue(5, 3, 4);
		d1.setvalue(2, 5, 8);
		d1.setvalue(1, 5, 7);
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    cout << "Symmetric Matrix :-" << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d1.getvalue(i, j) << " ";
        }
        cout << endl;
    }

	cout<<"\nChecking for some index not in list :-"<<endl;
    try
    {
        d1.getvalue(6, 6);
    }
    catch (const char *e)
    {
        cerr << e << endl;
    }

    return 0;
}