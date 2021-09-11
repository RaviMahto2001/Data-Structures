#include<iostream>
using namespace std;

void display_array(int x[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}

int SelectionSort(int x[],int n)
{
    int temp,min,minpos=0;
    cout<<"Selection sort ---"<<endl;
    for(int i=0;i<(n-1);i++)
    {
        min=x[i];minpos=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>x[j])
            {
                min=x[j];
                minpos=j;
            }
        }
        temp=x[i];
        x[i]=min;
        x[minpos]=temp;
        cout<<"array after pass "<<i+1<<" : ";
        display_array(x,n);
        cout<<endl;
    }
cout<<endl;
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

    SelectionSort(ary,n);
    cout<<endl;
    cout<<"Elements of array after sort : ";
    display_array(ary,n);
    cout<<endl;

    return 0;
}
