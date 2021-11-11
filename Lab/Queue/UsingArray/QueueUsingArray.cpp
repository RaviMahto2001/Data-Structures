#include <iostream>
using namespace std;

#define MAX 3

template <class T>
class Queue
{
private:
    T *x;
    int front;
    int rear;
    int s;
public:
    Queue()
    {
        x = new T[MAX];
        front=0;
        rear=0;
        s=0;
    }
    ~Queue()
    {delete[] x;}
    void enqueue(T value);
    void dequeue();
    bool empty();
    int size() {return s;}
    T getfront();
    void display();
};

class QueueException
{
private:
    string msg;
public:
    QueueException(string s)
    {
        msg = s;
    }
    string to_string()
    {
        return msg;
    }
};

template <class T>
void Queue<T>::enqueue(T value)
{
    if (s==MAX)
    {
        throw QueueException("Error! Queue Overflow.");
    }
    x[rear]=value;
    rear = (rear + 1) % MAX;
    s++;
}

template <class T>
void Queue<T>::dequeue()
{
    if (s == 0)
    {
        throw QueueException("Error! Queue Underflow.");
    }
    front = (front+1) % MAX;
    s--;
}

template <class T>
bool Queue<T>::empty()
{
    if (s == 0)
        return true;
    else
        return false;
}

template <class T>
T Queue<T>::getfront()
{
    if (s == 0)
        throw QueueException("error! Empty Queue");
    else
        return x[front];
}

template <class T>
void Queue<T>::display()
{
    if (s == 0)
    {
        cout << "empty" << endl;
        return;
    }
    int temp=front;
    do
    {
        cout << x[temp] << " << ";
        temp = (temp+1) % MAX;
    }while (temp!=rear);
    cout << endl;
}

Queue<char> q1; //global Queue variable

template <class T>
void EnqueueMenu()
{
    T element;
    cout << "Enter element to push : ";
    cin >> element;
    try{
        q1.enqueue(element);
    }
    catch(QueueException qe)
    {
        cout<<qe.to_string()<<endl;
        return;
    }
    cout << "--- Queue ---" << endl;
    q1.display();
}

template <class T>
void DequeueMenu()
{
    try
    {
        q1.dequeue();
    }
    catch (QueueException qe)
    {
        cout << qe.to_string() << endl;
        return;
    }

    cout << "Element removed successfully." << endl;
    cout << "--- Queue ---" << endl;
    q1.display();
}

template <class T>
void GetfrontMenu()
{
    T front_element;
    try
    {
        front_element = q1.getfront();
    }
    catch(QueueException qe)
    {
        cout << qe.to_string()<< endl;
        return;
    }
    cout<<"Front element of Queue : "<<front_element<<endl;   
}

void DisplayMenu()
{
    cout << "--- Queue ---" << endl;
    q1.display();
}

template <class T>
void menu()
{
    int choice;
    do
    {
        cout << "--- Queue Impelementation using Array ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Get Front" << endl;
        cout << "4. Get Size" << endl;
        cout << "5. Display" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            EnqueueMenu<T>();
            break;
        case 2:
            DequeueMenu<T>();
            break;
        case 3:
            GetfrontMenu<T>();
            break;
        case 4:
            cout<<"Size of Queue : "<<q1.size()<<endl;
            break;
        case 5:
            DisplayMenu();
            break;
        case 6:
            exit(0);
        default:
            cout << "Wrong!! choice try again..." << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    } while (choice != 6);
}
int main()
{
    menu<char>();
}