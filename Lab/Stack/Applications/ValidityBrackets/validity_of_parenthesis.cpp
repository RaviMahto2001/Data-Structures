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
	string x="(12+9*{23+12}*(12+5)/[6-8])/{7+1}";
	cout<<isvalid(x);
}
