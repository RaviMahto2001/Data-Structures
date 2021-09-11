#include<iostream>
using namespace std;

void insert_element(int x[],int& n,int pos,int element)
{
    for(int i=n;i>pos;i--)
    {
        x[i]=x[i-1];
    }
    x[pos]=element;
    n++;
}
int delete_element(int x[],int& n,int element)
{
    int check=0;
    for(int i=0;i<n;i++)
    {
        if(x[i]==element)
        {
            check=1;
            for(int j=i;j<n-1;j++)
            {
                x[j]=x[j+1];
            }
            x[n-1]=0;
            break;
        }
    }
    n--;
    return check;
}
void traverse(int x[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<x[i]<<" ";
    }
}
int main()
{
    int n=10;
    int ary[100]={0};
    ary[0]=3;
    ary[1]=5;
    ary[2]=7;
    ary[3]=9;
    ary[4]=13;
    ary[5]=6;
    ary[6]=4;
    ary[7]=1;
    ary[8]=10;
    ary[9]=8;

    cout<<"--- Array ---"<<endl;
    traverse(ary,n);
    cout<<endl;

    cout<<"--- Insert an element in array ---"<<endl;
    int element;
    int pos;
    cout<<"Enter the element you want to insert : ";cin>>element;
    cout<<"Enter the position : ";cin>>pos;
    insert_element(ary,n,pos-1,element);
    cout<<"--- Array ---"<<endl;
    traverse(ary,n);
    cout<<endl;

    cout<<"--- Delete an element from array ---"<<endl;
    cout<<"Enter the element you want to delete : ";cin>>element;
    int check;
    check = delete_element(ary,n,element);
    if(check==0)
    {
        cout<<"element not found..."<<endl;
    }
    else
    {
        cout<<"element deleted successfully..."<<endl;
    }
    cout<<"--- Array ---"<<endl;
    traverse(ary,n);
    cout<<endl;

}
