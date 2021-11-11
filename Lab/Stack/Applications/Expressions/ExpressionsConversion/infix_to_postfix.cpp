#include <iostream>
#include <stack>
using namespace std;
int prec(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

string infix_to_postfix(string x)
{
	string res = "";
	stack<char> st;
	for (int i = 0; i < x.length(); i++)
	{
		if ((x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
			res = res + x[i];
		else if (x[i] == '(')
			st.push('(');
		else if (x[i] == ')')
		{
			while (st.top() != '(')
			{
				res = res + st.top();
				st.pop();
			}
			st.pop();
		}
		else if (x[i] == '^')
		{
			st.push('^');
		}
		else
		{
			while ((!st.empty()) && (prec(x[i]) <= prec(st.top())))
			{
				res = res + st.top();
				st.pop();
			}
			st.push(x[i]);
		}
	}
	while (!st.empty())
	{
		res = res + st.top();
		st.pop();
	}
	return res;
}

int main()
{
	cout << "\n--- Infix To Postfix Conversion Program ---" << endl;

	string x1 = "a+b+D*c/S-v*g";
	string x2 = "a+(b+D)*c/S-v*g";
	string x3 = "(a+(b+D*c)/S-v*g)";
	string x4 = "a+(D*c/S-v)*g";
	string x5 = "a+b*c+s/d";
	string x6 = "a+g+b^c^d+e";

	cout << "\nExpression 1 : " << endl;
	cout << "Infix : " << x1 << endl;
	cout << "Postfix : " << infix_to_postfix(x1) << endl;
	cout << "\nExpression 2 : " << endl;
	cout << "Infix : " << x2 << endl;
	cout << "Postfix : " << infix_to_postfix(x2) << endl;
	cout << "\nExpression 3 : " << endl;
	cout << "Infix : " << x3 << endl;
	cout << "Postfix : " << infix_to_postfix(x3) << endl;
	cout << "\nExpression 4 : " << endl;
	cout << "Infix : " << x4 << endl;
	cout << "Postfix : " << infix_to_postfix(x4) << endl;
	cout << "\nExpression 5 : " << endl;
	cout << "Infix : " << x5 << endl;
	cout << "Postfix : " << infix_to_postfix(x5) << endl;
	cout << "\nExpression 6 : " << endl;
	cout << "Infix : " << x6 << endl;
	cout << "Postfix : " << infix_to_postfix(x6) << endl;
	cout << endl;
	return 0;
}