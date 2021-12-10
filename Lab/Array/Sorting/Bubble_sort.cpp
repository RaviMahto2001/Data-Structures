#include<iostream>
using namespace std;

void display_array(int x[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}

void BubbleSort(int x[],int n)
{
    int temp;
    cout<<"Bubble sort ---"<<endl;
    for(int i=0;i<(n-1);i++)
    {
        for(int j=0;j<(n-i-1);j++)
        {
            if(x[j]>x[j+1])
            {
                temp=x[j+1];
                x[j+1]=x[j];
                x[j]=temp;
            }
        }
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

    BubbleSort(ary,n);
    cout<<endl;
    cout<<"Elements of array after sort : ";
    display_array(ary,n);
    cout<<endl;

    return 0;
}
