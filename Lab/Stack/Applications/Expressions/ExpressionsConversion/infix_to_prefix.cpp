#include <iostream>
#include <stack>
using namespace std;
int prec(char c)
{
	if(c=='^')
		return 3;
	else if(c=='/' || c=='*')
		return 2;
	else if(c=='+' || c=='-')
		return 1;
	else
		return -1;
}

string infix_to_prefix(string x)
{	
	string res="";
	stack<char> st;
	for(int i=x.length()-1;i>=0;i--)
	{
		if((x[i]>='a' && x[i]<='z') || (x[i]>='A' && x[i]<='Z'))
			res = x[i] + res;
		else if(x[i]==')')
			st.push(x[i]);
		else if(x[i]=='(')
		{
			while(st.top()!=')')
			{
				res = st.top() + res;
				st.pop();
			}
			st.pop();
		}
		else if(x[i]=='^')
		{
			while((!st.empty()) && (prec(x[i]) <=prec(st.top())))
			{
				res = st.top() + res;
				st.pop();
			}	
			st.push(x[i]);
		}
		else
		{
			while((!st.empty()) && (prec(x[i])<prec(st.top())))
			{
				res = st.top() + res;
				st.pop();
			}
			st.push(x[i]);	
		}	
	}
	while(!st.empty())
	{
		res = st.top() + res;
		st.pop();
	}
return res;
}

int main()
{
cout << "\n--- Infix To Prefix Conversion Program ---" << endl;

	string x1 = "a+b+D*c/S-v*g";
	string x2 = "a+(b+D)*c/S-v*g";
	string x3 = "(a+(b+D*c)/S-v*g)";
	string x4 = "a+(D*c/S-v)*g";
	string x5 = "a+b*c+s/d";
	string x6 = "a+g+b^c^d+e";

	cout << "\nExpression 1 : " << endl;
	cout << "Infix : " << x1 << endl;
	cout << "Prefix : " << infix_to_prefix(x1) << endl;
	cout << "\nExpression 2 : " << endl;
	cout << "Infix : " << x2 << endl;
	cout << "Prefix : " << infix_to_prefix(x2) << endl;
	cout << "\nExpression 3 : " << endl;
	cout << "Infix : " << x3 << endl;
	cout << "Prefix : " << infix_to_prefix(x3) << endl;
	cout << "\nExpression 4 : " << endl;
	cout << "Infix : " << x4 << endl;
	cout << "Prefix : " << infix_to_prefix(x4) << endl;
	cout << "\nExpression 5 : " << endl;
	cout << "Infix : " << x5 << endl;
	cout << "Prefix : " << infix_to_prefix(x5) << endl;
	cout << "\nExpression 6 : " << endl;
	cout << "Infix : " << x6 << endl;
	cout << "Prefix : " << infix_to_prefix(x6) << endl;
	cout << endl;
return 0;
}
