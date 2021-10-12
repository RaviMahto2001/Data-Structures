#include<iostream>
#include<exception>
using namespace std;

template <class U>
class node{
	private:
	U data;
	node<U>* next;
	public:
	node(U value){
		data=value;
		next=NULL;
	}
template <class T> friend class Stack;
};

template <class T>
class Stack{
	private:
	node<T>* top;
	public:
	Stack(){
		top = NULL;
	}
	void push(T value);
	T pop();
	T peek();
	void display();

};

class StackException
{
	string msg;
	public:
	StackException(string msg)
	{
		this->msg = msg;
	}
	string to_string()
	{
		return msg;
	}
};

template <class T>
void Stack<T> :: push(T value)
{
	node<T>* n = new node<T>(value);
	if(!n)
	{
		throw StackException("Stack Overflow!!");
	}
	n->next = top;
	top = n;	
}

template <class T>
T Stack<T> :: pop(){
	if(top==NULL){
		throw StackException("Stack Underflow!!");
	}
	T x=top->data;
	node<T>* temp = top;
	top = top->next;
	delete temp;
	return x;
}

template <class T>
T Stack<T> :: peek(){
	if(top==NULL)
		throw StackException("Stack is Empty");
	else
		return top->data;
}

template <class T>
void Stack<T> :: display(){
	if(top==NULL){
		cout<<"Empty Stack"<<endl; 
		return; 
	}
	cout<<"top ->  "<<top->data<<endl;
	node<T>* temp = top->next;
	while(temp!=NULL)
	{
		cout<<"        "<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<"        "<<"NULL"<<endl;
}

	string type_s1;
	Stack<type_s1> s1; //global stack variable

template <class T>
void PushMenu()
{
	T element;
	cout<<"Enter element to push : "; cin>>element;
	try{
	s1.push(element);
	}catch(StackException se)
	{cout<<se.to_string()<<endl; return;}
	cout<<"--- Stack ---"<<endl;
	s1.display();
}
template <class T>
void PopMenu()
{
	T poped;
	try{
		poped=s1.pop();
	}catch(StackException se)
	{cout<<se.to_string()<<endl; return;}

	cout<<"Element poped :"<<poped<<endl;
	cout<<"--- Stack ---"<<endl;
	s1.display();
}
template <class T>
void PeekMenu()
{
	T topelement;
	try{
		topelement=s1.peek();
	}catch(StackException se)
	{cout<<se.to_string()<<endl; return;}

	cout<<"Element at top of Stack : ";
	cout<<topelement<<endl;
}

void DisplayMenu()
{
	cout<<"--- Stack ---"<<endl;
	s1.display();
}

template <class T>
void menu()
{ 	int choice;
	do
	{
		cout<<"--- Stack Impelementation using linked list ---"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peek"<<endl;
		cout<<"4. Display"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Enter your choice : ";cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1: PushMenu<T>(); break;
			case 2: PopMenu<T>();break;
			case 3: PeekMenu<T>();break;
			case 4: DisplayMenu();break;
			case 5: exit(0);
			default: cout<<"Wrong!! choice try again..."<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(choice!=5);
}

int main(){
	cout<<"Enter the type of elements of Stack : "; cin>>type_s1;
	if(type_s1 == "int")
		menu<int>();
	else if(type_s1 == "char")
		menu<char>();
	else if(type_s1 == "double")
		menu<double>();
	else if(type_s1 == "float")
		menu<float>();
	else if(type_s1 == "string")
		menu<string>();
	else
		cout<<"Unexpected data type!!"<<endl;
}




