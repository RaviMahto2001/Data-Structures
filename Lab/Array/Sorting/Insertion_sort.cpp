#include<iostream>
using namespace std;

void display_array(int x[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}

int InsertionSort(int x[],int n)
{
    int temp;
    int j;
    for(int i=1;i<n;i++)
    {
        temp=x[i];
        j=i-1;
        while(j>=0 && x[j]>temp)
        {
            x[j+1]=x[j];
            j--;
        }
        x[j+1]=temp;

        cout<<"array after pass "<<i<<" : ";
        display_array(x,n);
        cout<<endl;
    }
}

int main()
{
    int n;
    cout<<"How many no you want to enter in array : ";cin>>n;
    int ary[n];
    cout<<"Enter elements of array ---"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>ary[i];
    }

    InsertionSort(ary,n);
    cout<<endl;
    cout<<"Elements of array after sort : ";
    display_array(ary,n);
    cout<<endl;

    return 0;
}
