#include<iostream>
#include<stack>
using namespace std;

template <class T>
class Stack{
	private:
	stack<T> s;
	stack<T> aux;
	public:
	void push(T x)
	{
		if(s.empty())
		{
			s.push(x);
			aux.push(x);
		}
		else
		{
			s.push(x);
			if(x<=aux.top())
				aux.push(x);
		}
	}
	T pop()
	{
		if(s.empty())
			return -1;
		else
		{
			int x=s.top();
			if(x==aux.top())
				aux.pop();
			s.pop();
			return x;
		}
	}
	
	T getMin()
	{
		return aux.top();
	}
};

int main()
{
	Stack<int> s1;
	s1.push(12);
	cout<<s1.getMin()<<endl;
	s1.push(12);     
	cout<<s1.getMin()<<endl;
	s1.push(15);     
	cout<<s1.getMin()<<endl;
	s1.push(10);     
	cout<<s1.getMin()<<endl;
}




