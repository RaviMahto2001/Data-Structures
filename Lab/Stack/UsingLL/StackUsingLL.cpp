#include<iostream>
using namespace std;

class node{
	private:
	int data;
	node* next;
	public:
	node(int value){
		data=value;
		next=NULL;
	}
friend class Stack;
};

class Stack{
	private:
	node* top;
	public:
	Stack(){
		top = NULL;
	}
	void push(int value);
	int pop();
	int peek();
	bool isempty()
	{return (top==NULL)? true:false;}
	void display();
};
void Stack :: push(int value)
{
	node* n = new node(value);
	if(!n)
	{
		cout<<"Stack Overflow!!"<<endl;
		exit(1);
	}
	n->next = top;
	top = n;	
}

int Stack :: pop(){
	if(top==NULL){
		cout<<"Stack Underflow!!"<<endl;
		return -1;
	}
	int x=top->data;
	node* temp = top;
	top = top->next;
	delete temp;
	return x;
}

int Stack :: peek(){
	if(top==NULL)
		return -1;
	else
		return top->data;
}

void Stack :: display(){
	if(top==NULL){
		cout<<"Empty Stack"<<endl; 
		return; 
	}
	cout<<"top ->  "<<top->data<<endl;
	node* temp = top->next;
	while(temp!=NULL)
	{
		cout<<"        "<<temp->data<<endl;
		temp=temp->next;
	}
	cout<<"        "<<"NULL"<<endl;
}

	Stack s1; //global stack variable

void PushMenu()
{
	int element;
	cout<<"Enter element to push : "; cin>>element;
	s1.push(element);
	cout<<"--- Stack ---"<<endl;
	s1.display();
}
void PopMenu()
{
	int poped=s1.pop();

	if(poped==-1) return;

	cout<<"Element poped :"<<poped<<endl;
	cout<<"--- Stack ---"<<endl;
	s1.display();
}
void PeekMenu()
{
	int topelement=s1.peek();
	if(topelement==-1)
		cout<<"Stack is empty"<<endl;
	else
	{
		cout<<"Element at top of Stack : ";
		cout<<topelement<<endl;
	}
}
void DisplayMenu()
{
	cout<<"--- Stack ---"<<endl;
	s1.display();
}

void menu()
{ 	int choice;
	do
	{
		cout<<"--- Stack Impelementation using linked list ---"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peek"<<endl;
		cout<<"4. isEmpty"<<endl;
		cout<<"5. Display"<<endl;
		cout<<"6. Exit"<<endl;
		cout<<"Enter your choice : ";cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1: PushMenu(); break;
			case 2: PopMenu();break;
			case 3: PeekMenu();break;
			case 4: if(s1.isempty())
						cout<<"Stack is empty."<<endl;
					else
						cout<<"Stack is not empty."<<endl;
					break;
			case 5: DisplayMenu();break;
			case 6: exit(0);
			default: cout<<"Wrong!! choice try again..."<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(choice!=6);
}
int main(){
	menu();
}
