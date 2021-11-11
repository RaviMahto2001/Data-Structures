#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> num1;
    stack<int> num2;
    stack<int> result;
    string n1;
    string n2;
    cout << "Enter Num1 :- " << endl;
    cin >> n1;
    cout << "Enter Num2 :- " << endl;
    cin >> n2;
    int i = 0;
    while (i < n1.length())
    {
        num1.push((n1[i] - '0'));
        i++;
    }
    i = 0;
    while (i < n2.length())
    {
        num2.push((n2[i] - '0'));
        i++;
    }

    int sum = 0;
    int carry = 0;
    int x, y;
    while (!num1.empty() && !num2.empty())
    {
        x = num1.top();
        num1.pop();
        y = num2.top();
        num2.pop();
        sum = x + y + carry;
        result.push(sum % 10);
        carry = sum / 10;
    }
    if (num1.empty())
    {
        while (!num2.empty())
        {
            y = num2.top();
            num2.pop();
            result.push(y + carry);
            carry = 0;
        }
        if (carry != 0)
        {
            result.push(carry);
        }
    }
    else
    {
        while (!num1.empty())
        {
            x = num1.top();
            num1.pop();
            result.push(x + carry);
            carry = 0;
        }
        if (carry != 0)
        {
            result.push(carry);
        }
    }

    cout << "Sum  : ";
    while (!result.empty())
    {
        cout << result.top();
        result.pop();
    }
    cout << endl;

    return 0;
}
