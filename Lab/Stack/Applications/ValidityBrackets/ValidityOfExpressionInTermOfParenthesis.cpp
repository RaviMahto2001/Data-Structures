#include<iostream>
#include<stack>
using namespace std;

bool isvalid(string x)
{
	stack<char> st;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='(' || x[i]=='{' || x[i] =='[')
			st.push(x[i]);
		else if(x[i]==')' || x[i]=='}' || x[i] ==']')
		{
			if(st.empty())
			return false;
			else
			{
				if(st.top()=='(' && x[i]==')')
					st.pop();
				else if(st.top()=='{' && x[i]=='}')
					st.pop();
				else if(st.top()=='[' && x[i]==']')
					st.pop();
				else
					return false;
			}
		}
		else continue;
	}
return st.empty();
}

int main()
{
    cout<<"\n--- Validity of Expression in terms of Paranthesis ---"<<endl;
	string x1="(12+9*{23+12}*(12+5)/[6-8])/{7+1}";
    cout<<"\nExpression 1 : "<<endl;
    cout<<x1<<endl;
	if(isvalid(x1))
        cout<<"Expression is Valid."<<endl;
    else
        cout<<"Expression is invalid."<<endl;
    cout<<endl;
	string x2="[(){}[]]";
    cout<<"\nExpression 2 : "<<endl;
    cout<<x2<<endl;
	if(isvalid(x2))
        cout<<"Expression is Valid."<<endl;
    else
        cout<<"Expression is invalid."<<endl;
    cout<<endl;
	string x3="({[}])";
    cout<<"\nExpression 3 : "<<endl;
    cout<<x3<<endl;
	if(isvalid(x3))
        cout<<"Expression is Valid."<<endl;
    else
        cout<<"Expression is invalid."<<endl;
    cout<<endl;
return 0;
}
