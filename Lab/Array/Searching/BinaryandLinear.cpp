#include <iostream>
using namespace std;

//Binary Search
int BinarySearch(int x[], int n, int element)
{
    int mid, start = 0, last = n - 1;
    int NoComp = 0;
    while (start <= last)
    {
        NoComp++;
        mid = (start + last) / 2;
        if (x[mid] == element)
        {
            cout << "No of Comparison in Binary Search : " << NoComp << endl;
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
    cout << "No of Comparison in Binary Search : " << NoComp << endl;
    return -1;
}

// Linear Search
int LinearSearch(int x[], int n, int element)
{
    int index = -1;
    int NoComp = 0;
    for (int i = 0; i < n; i++)
    {
        NoComp++;
        if (x[i] == element)
        {
            index = i;
            break;
        }
    }
    cout << "No of Comparison in Linear Search : " << NoComp << endl;
    return index;
}

//main
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

    int element;
    cout << "Enter the element you want to search : ";
    cin >> element;

    cout << "--- Searching element using Binary Search ---" << endl;
    int index, NoCompBinary;
    index = BinarySearch(x, n, element);
    if (index == -1)
    {
        cout << "Element not found..." << endl;
    }
    else
    {
        cout << "Element found at index " << index << endl;
    }

    cout << endl;
    index = 0;
    cout << "--- Searching element using Linear Search ---" << endl;
    index = LinearSearch(x, n, element);
    if (index == -1)
    {
        cout << "Element not found..." << endl;
    }
    else
    {
        cout << "Element found at index " << index << endl;
    }
}
