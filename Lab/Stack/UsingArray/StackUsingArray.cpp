#include<iostream>
using namespace std;

#define MAX 100

class Stack{
private:
    int* x;
    int top;
public:
    Stack()
    {
        x=new int[MAX];
        top=-1;
    }
    void push(int value);
    int pop();
    int peek();
	bool isempty()
	{return (top == -1)? true : false;}
	bool isfull()
	{return (top == MAX-1)? true : false;}
    void display();
};

void Stack :: push(int value)
{
    if(top==MAX-1)
    {
        cout<<"Stack Overflow!!"<<endl;
        return;
    }
    x[++top]=value;
}
int Stack :: pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow!!"<<endl;
        return -1;
    }
    return x[top--];
}
int Stack :: peek()
{
    if(top==-1) return -1;
    else return x[top];
}
void Stack :: display(){
	if(top==-1){
		cout<<"Empty Stack"<<endl; 
		return; 
	}
	cout<<"top ->  "<<x[top]<<endl;
	int temp = top-1;
	while(temp!=-1)
	{
		cout<<"        "<<x[temp]<<endl;
		temp--;
	}
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
		cout<<"--- Stack Impelementation Using Array ---"<<endl;
		cout<<"1. Push"<<endl;
		cout<<"2. Pop"<<endl;
		cout<<"3. Peek"<<endl;
		cout<<"4. isFull"<<endl;
		cout<<"5. isEmpty"<<endl;
		cout<<"6. Display"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter your choice : ";cin>>choice;
		cout<<endl;
		switch(choice)
		{
			case 1: PushMenu(); break;
			case 2: PopMenu();break;
			case 3: PeekMenu();break;
			case 4: if(s1.isfull())
						cout<<"Stack is Full."<<endl;
					else
						cout<<"Stack is not Full."<<endl;
					break;
			case 5: if(s1.isempty())
						cout<<"Stack is empty."<<endl;
					else
						cout<<"Stack is not empty."<<endl;
					break;
			case 6: DisplayMenu();break;
			case 7: exit(0);
			default: cout<<"Wrong!! choice try again..."<<endl;
		}
		cout<<endl;
		system("pause");
		system("cls");
	}while(choice!=7);
}
int main(){
	menu();
}
