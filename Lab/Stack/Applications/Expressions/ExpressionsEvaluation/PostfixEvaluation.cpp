#include <bits/stdc++.h>
using namespace std;

int evalpostfix(string x)
{
	stack<int> st;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]>='0' && x[i]<='9')
		{
			int op=0;
			while(x[i]!=' ')
			{
				op = op*10 + (x[i]-'0');
				i++;
			}
			st.push(op);
		}
		else if (x[i]==' ')
		{
			continue;
		}
		else
		{
			int op2=st.top();
			st.pop();
			int op1=st.top();
			st.pop();
			switch(x[i])
			{
				case '+':
				st.push(op1 + op2); break;
				case '-':
				st.push(op1 - op2); break;
				case '*':
				st.push(op1 * op2); break;
				case '/':
				st.push(op1 / op2); break;
				case '^':
				st.push(pow(op1,op2)); break;
			}
		}
	}
return st.top();
}
int main()
{
	cout<<"--- Postfix Evaluation Using Stack --- "<<endl;
	string x1="5 3 ^ 23 456 9 / * +";
	string x2="5 2 - 3 2 2 ^ ^ +";
	cout<<endl;
	cout<<"Expression 1 : "<<endl;
	cout<<x1<<endl;
	cout<<"Result : "<<evalpostfix(x1)<<endl;
	cout<<endl;
	cout<<"Expression 2 : "<<endl;
	cout<<x2<<endl;
	cout<<"Result : "<<evalpostfix(x2)<<endl;
	cout<<endl;
return 0;
}
