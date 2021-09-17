#include<iostream>
using namespace std;

template <class T>
class node{
    private:
    T data;
    node<T> *next;
    node<T> *prev;
    public:
    node(T value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }

    template <class X> friend class SDLL;
};

template <class T>
class SDLL{
    private:
    node<T>* head;
    node<T>* tail;
    public:
    SDLL()
    {
        head=NULL;
        tail=NULL;
    }
    node<T>* gethead() {return head;}
    node<T>* gettail() {return tail;}
    void Insert(T value);
    bool Delete(T value);
    void traverse_forward();
    void traverse_backward();
    node<T>* search(T element);
};

template <class T>
void SDLL<T> :: Insert(T value)
{
    node<T> *n = new node<T>(value);
    if(head==NULL)
    {
        head=n;
        tail=n;
        return;
    }
    if(head!=NULL && head->data>=value)
    {
        head->prev=n;
        n->next=head;
        head=n;
        return;
    }
    if(tail!=NULL && tail->data<=value)
    {
        tail->next=n;
        n->prev=tail;
        tail=n;
        return;
    }
    node<T>* temp = head->next;
    while(temp!=NULL)
    {
        if(temp->data>=value)
        {
            temp->prev->next=n;
            n->prev=temp->prev;
            n->next=temp;
            temp->prev=n;
            return;
        }
        temp=temp->next;
    }
}

template <class T>
bool SDLL<T> :: Delete(T value)
{
   if(head==NULL) return false;
   if(head->data==value)
   {
       head=head->next;
       delete head->prev;
       head->prev=NULL;
       return true;
   }
   if(tail->data==value)
   {
       tail=tail->prev;
       delete tail->next;
       tail->next=NULL;
       return true;
   }
   node<T>* temp=head->next;
   while(temp!=NULL)  
   {
       if(temp->data==value)
       {
           temp->prev->next=temp->next;
           temp->next->prev=temp->prev;
           delete temp;
           return true;
       }
       temp=temp->next;
   }
   return false;
}

template <class T>
void SDLL<T> :: traverse_forward()
{
    node<T>* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template <class T>
void SDLL<T> :: traverse_backward()
{
    node<T>* temp = tail;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

template <class T>
node<T>* SDLL<T> :: search(T element)
{
    if(head->data>element) return NULL;
    if(tail->data<element) return NULL;
    node<T>* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==element) return temp;
        if(temp->data>element) return NULL;
        temp=temp->next;
    }
    return NULL;
}

int main()
{
cout<<endl;

    SDLL<int> l1;
    l1.Insert(10);
    l1.Insert(30);
    l1.Insert(20);
    l1.Insert(40);
    l1.Insert(22);
    cout<<"--- int type List 1 ---"<<endl;
    cout<<"Forward traversing  : ";
    l1.traverse_forward();
    cout<<"Backward traversing : ";
    l1.traverse_backward();

    cout<<"Searching :- "<<endl;
    cout<<"searching for 22 :-"<<endl;
    node<int>* loc11=l1.search(22);
    if(loc11!=NULL)
        cout<<"element found at location : "<<loc11<<endl;
    else 
        cout<<"element not found."<<endl;
    cout<<"searching for 19 :-"<<endl;
    node<int>* loc12=l1.search(19);
    if(loc12!=NULL)
        cout<<"element found at location : "<<loc12<<endl;
    else 
        cout<<"element not found."<<endl;

    cout<<"Deletion :- "<<endl;
    cout<<"deleting 20 from list..."<<endl;
    if(l1.Delete(20))
    {
        cout<<"deletion successfull. "<<endl;
        cout<<"Forward traversing  : ";
        l1.traverse_forward();
        cout<<"Backward traversing : ";
        l1.traverse_backward();
    }
    else
        cout<<"error! deleting element. "<<endl;

cout<<endl;

    SDLL<double> l2;
    l2.Insert(10.3);
    l2.Insert(30.5);
    l2.Insert(20.7);
    l2.Insert(40.23);
    l2.Insert(20.75);
    cout<<"--- double type List 2 ---"<<endl;
    cout<<"Forward traversing  : ";
    l2.traverse_forward();
    cout<<"Backward traversing : ";
    l2.traverse_backward();

    cout<<"Searching :- "<<endl;
    cout<<"searching for 40.23 :-"<<endl;
    node<double>* loc21=l2.search(40.23);
    if(loc21!=NULL)
        cout<<"element found at location : "<<loc21<<endl;
    else 
        cout<<"element not found."<<endl;
    cout<<"searching for 19.5 :-"<<endl;
    node<double>* loc22=l2.search(19.5);
    if(loc22!=NULL)
        cout<<"element found at location : "<<loc22<<endl;
    else 
        cout<<"element not found."<<endl;

    cout<<"Deletion :- "<<endl;
    cout<<"deleting 20.7 from list..."<<endl;
    if(l2.Delete(20.7))
    {
        cout<<"deletion successfull. "<<endl;
        cout<<"Forward traversing  : ";
        l2.traverse_forward();
        cout<<"Backward traversing : ";
        l2.traverse_backward();
    }
    else
        cout<<"error! deleting element. "<<endl;

cout<<endl;

    SDLL<string> l3;
    l3.Insert("abcd");
    l3.Insert("abc");
    l3.Insert("bcde");
    l3.Insert("aab");
    l3.Insert("xyz");
    cout<<"--- string type List 3 ---"<<endl;
    cout<<"Forward traversing  : ";
    l3.traverse_forward();
    cout<<"Backward traversing : ";
    l3.traverse_backward();

    cout<<"Searching :- "<<endl;
    cout<<"searching for abc :-"<<endl;
    node<string>* loc31=l3.search("abc");
    if(loc31!=NULL)
        cout<<"element found at location : "<<loc31<<endl;
    else 
        cout<<"element not found."<<endl;
    cout<<"searching for Hello :-"<<endl;
    node<string>* loc32=l3.search("Hello");
    if(loc32!=NULL)
        cout<<"element found at location : "<<loc32<<endl;
    else 
        cout<<"element not found."<<endl;

    cout<<"Deletion :- "<<endl;
    cout<<"deleting abcd from list..."<<endl;
    if(l3.Delete("abcd"))
    {
        cout<<"deletion successfull. "<<endl;
        cout<<"Forward traversing  : ";
        l3.traverse_forward();
        cout<<"Backward traversing : ";
        l3.traverse_backward();
    }
    else
        cout<<"error! deleting element. "<<endl;
cout<<endl; 
return 0;
}