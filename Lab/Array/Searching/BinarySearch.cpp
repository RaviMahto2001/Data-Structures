#include <iostream>
using namespace std;
int BinarySearch(int x[], int n, int element)
{
    int mid, start = 0, last = n - 1;
    while (start <= last)
    {
        mid = (start + last) / 2;
        if (x[mid] == element)
        {
            return mid;
        }
        else if (x[mid] > element)
        {
            last = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n = 8;
    int x[n] = {1, 4, 6, 12, 23, 34, 45, 50};

    cout << "--- Array ---" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;

    int element, index;
    cout << "Enter the element you want to search : ";
    cin >> element;
    index = BinarySearch(x, n, element);
    if(index==-1)
    {
        cout << "Element not found..." << endl;
    }
    else
    {
        cout << "Element found at index " <<index<< endl;
    }
}