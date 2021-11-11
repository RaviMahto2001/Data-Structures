#include <bits/stdc++.h>
using namespace std;

template <class T>
class node
{
private:
    T data;
    node<T>* next;
public:
    node(T value)
    {
        data = value;
        next = NULL;
    }
    template <class U>
    friend class Queue;
};

template <class T>
class Queue
{
private:
    node<T> *front;

public:
    Queue()
    {
        front == NULL;
    }
    void enqueue(T value);
    T dequeue();
    bool isempty();
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
    node<T> *n = new node<T>(value);
    node<T> *temp = front;
    if (!n)
    {
        throw QueueException("Error! Heap Overflow.");
    }
    if (front == NULL)
    {
        front = n;
        return;
    }
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

template <class T>
T Queue<T>::dequeue()
{
    if (front == NULL)
    {
        throw QueueException("Error! Queue Underflow.");
    }
    node<T> *todel;
    T x = front->data;
    todel = front;
    front = front->next;
    delete todel;
    return x;
}

template <class T>
bool Queue<T>::isempty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

template <class T>
void Queue<T>::display()
{
    if (front == NULL)
    {
        cout << "empty" << endl;
        return;
    }

    node<T> *temp = front;
    while (temp != NULL)
    {
        cout << temp->data << " << ";
        temp = temp->next;
    }
    cout << endl;
}

Queue<int> q1; //global Queue variable

void EnqueueMenu()
{
    int element;
    cout << "Enter element to push : ";
    cin >> element;
    try{
        q1.enqueue(element);
    }catch(QueueException qe)
    {
        cout<<qe.to_string()<<endl;
    }
    cout << "--- Queue ---" << endl;
    q1.display();
}
void DequeueMenu()
{
    int el;
    try
    {
        el = q1.dequeue();
    }
    catch (QueueException qe)
    {
        cout << qe.to_string() << endl;
    }

    cout << "Element removed :" << el << endl;
    cout << "--- Queue ---" << endl;
    q1.display();
}

void DisplayMenu()
{
    cout << "--- Queue ---" << endl;
    q1.display();
}

void menu()
{
    int choice;
    do
    {
        cout << "--- Queue Impelementation using linked list ---" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;
        cout << endl;
        switch (choice)
        {
        case 1:
            EnqueueMenu();
            break;
        case 2:
            DequeueMenu();
            break;
        case 3:
            DisplayMenu();
            break;
        case 4:
            exit(0);
        default:
            cout << "Wrong!! choice try again..." << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    } while (choice != 4);
}
int main()
{
    menu();
}