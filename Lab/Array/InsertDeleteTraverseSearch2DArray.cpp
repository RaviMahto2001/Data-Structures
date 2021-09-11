#include<iostream>
using namespace std;

const int imax=4;
const int jmax=5;

void Traverse(int x[][5])
{
    for(int i=0;i<imax;i++)
    {
        for(int j=0;j<jmax;j++)
        {
            cout<<x[i][j]<<" ";
        }
        cout<<endl;
    }
}
int Delete_element(int x[][5],int element)
{
    int check=0;
    for(int i=0;i<imax;i++)
    {
        for(int j=0;j<jmax;j++)
        {
            if(x[i][j]==element)
            {
                x[i][j]=-1;
                check=1;
            }
        }
    }
    return check;
}
void Search_element(int x[][5],int element)
{
    int check=0;
    for(int i=0;i<imax;i++)
    {
        for(int j=0;j<jmax;j++)
        {
            if(x[i][j]==element)
            {
                cout<<"element found at index "<<i<<" "<<j<<" "<<endl;
                check=1;
            }
        }
    }
    if(check==0)
    {
        cout<<"element not found..."<<endl;
    }
}
int Insert_element(int x[][5],int i,int j,int element)
{
    int check=0;
    if((i>=0 && i<imax ) && (j>=0 && j<jmax))
    {
        x[i][j]=element;
        check=1;
    }
    return check;
}
int main()
{
    int ary2D[imax][jmax]={{6,7,4,3,20},{22,34,45,14,15},{32,31,58,66,21},{1,5,12,10,11}};
    cout<<"--- Array ---"<<endl;
    Traverse(ary2D);
    cout<<endl;

    int flag;
    int element;
    cout<<"--- Delete element ---"<<endl;
    cout<<"Enter the element to be Deleted : ";cin>>element;
    flag=Delete_element(ary2D,element);
    if(flag==1)
    {
        cout<<"element deleted successfully..."<<endl;
    }
    else
    {
        cout<<"element not found..."<<endl;
    }
    cout<<endl;
    cout<<"--- Array ---"<<endl;
    Traverse(ary2D);
    cout<<endl;

    int ipos,jpos;
    cout<<"--- Insert element ---"<<endl;
    cout<<"Enter the element to be entered : ";cin>>element;
    cout<<"Enter the ith jth position : ";cin>>ipos;cin>>jpos;
    flag=Insert_element(ary2D,ipos,jpos,element);
    if(flag==1)
    {
        cout<<"element inserted successfully..."<<endl;
    }
    else
    {
        cout<<"can't insert element..."<<endl;
    }
    cout<<endl;
    cout<<"--- Array ---"<<endl;
    Traverse(ary2D);
    cout<<endl;

    cout<<"--- Search element ---"<<endl;
    cout<<"Enter the element to be Searched : ";cin>>element;
    Search_element(ary2D,element);
    cout<<endl;

return 0;
}
