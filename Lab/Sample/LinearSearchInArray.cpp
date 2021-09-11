#include<iostream>
using namespace std;
int LinearSearch(int x[],int n,int element)
{
    int index=-1;
    for(int i=0;i<n;i++)
    {
        if(x[i]==element)
        {
            index=i;
            break;
        }
    }
    return index;
}
int main()
{
    int ary[]={7,9,4,5,2,3,12,15,3,1};
    cout<<"--- Array ---"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<ary[i]<<" ";
    }
    cout<<endl;
    int element,index;
    cout<<"Enter the element you want to search : ";cin>>element;
    cout<<endl;
    index=LinearSearch(ary,10,element);
    if(index==-1)
    {
        cout<<"Element not found."<<endl;
    }
    else
    {
        cout<<"Element found at index "<<index<<endl;
    }
}
