#include <iostream>
using namespace std;

template <class T>
class node
{
private:
    T data;
    node<T> *next;

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
    T *x;
    node<T> *front;
    int s;

public:
    Queue()
    {
        front = NULL;
        s = 0;
    }

    void enqueue(T value);
    void dequeue();
    bool empty();
    int size() { return s; }
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
    node<T> *n = new node<T>(value);
    if (!n)
    {
        throw QueueException("Error! Heap Overflow.");
    }
    if (front == NULL)
    {
        front = n;
        n->next = front;
        s++;
        return;
    }
    node<T> *temp = front;
    while (temp->next != front)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = front;
    s++;
}

template <class T>
void Queue<T>::dequeue()
{
    if (front == NULL)
    {
        throw QueueException("Error! Queue Underflow.");
    }
    if (s == 1)
    {
        delete front;
        front = NULL;
        s--;
        return;
    }
    node<T> *todel = front;
    front = front->next;
    node<T> *temp = front;
    while (temp->next != todel)
    {
        temp = temp->next;
    }
    temp->next = front;
    delete todel;
    s--;
}

template <class T>
bool Queue<T>::empty()
{
    if (front == NULL)
        return true;
    else
        return false;
}

template <class T>
T Queue<T>::getfront()
{
    if (front == NULL)
        throw QueueException("error!! Queue is empty.");
    else
        return front->data;
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
    do
    {
        cout << temp->data << " << ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

Queue<int> q1; //global Queue variable

template <class T>
void EnqueueMenu()
{
    T element;
    cout << "Enter element to push : ";
    cin >> element;
    try
    {
        q1.enqueue(element);
    }
    catch (QueueException qe)
    {
        cout << qe.to_string() << endl;
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
    catch (QueueException qe)
    {
        cout << qe.to_string() << endl;
        return;
    }
    cout << "Front element of Queue : " << front_element << endl;
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
            cout << "Size of Queue : " << q1.size() << endl;
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
    menu<int>();
}