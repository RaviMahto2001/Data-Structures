#include <bits/stdc++.h>
using namespace std;

int evalprefix(string x)
{
	stack<int> st;
	for(int i=x.length()-1;i>=0;i--)
	{
		if(x[i]>='0' && x[i]<='9')
		{
			int op=0,mul=1;
			while(x[i]!=' ')
			{
				op = op + (x[i]-'0')*mul;
				mul *= 10;
				i--;
			}
			st.push(op);
		}
		else if (x[i]==' ')
		{
			continue;
		}
		else
		{
			int op1=st.top();
			st.pop();
			int op2=st.top();
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
	cout<<"--- Prefix Evaluation Using Stack --- "<<endl;
	string x1="+ * / 456 9 23 ^ 5 3";
	string x2="+ - 5 2 ^ 3 ^ 2 2";
	cout<<endl;
	cout<<"Expression 1 : "<<endl;
	cout<<x1<<endl;
	cout<<"Result : "<<evalprefix(x1)<<endl;
	cout<<endl;
	cout<<"Expression 2 : "<<endl;
	cout<<x2<<endl;
	cout<<"Result : "<<evalprefix(x2)<<endl;
	cout<<endl;
return 0;
}
