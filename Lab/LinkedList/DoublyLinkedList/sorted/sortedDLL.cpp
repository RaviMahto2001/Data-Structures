#include<iostream>
using namespace std;

class node{
    private:
    int data;
    node *next;
    node *prev;
    public:
    node(int value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }

    friend class SDLL;
    friend int main();
};

class SDLL{
    private:
    node* head;
    node* tail;
    public:
    SDLL()
    {
        head=NULL;
        tail=NULL;
    }
    node* gethead() {return head;}
    node* gettail() {return tail;}
    void Insert(int value);
    bool Delete(int value);
    void traverse_forward();
    void traverse_backward();
    node* search(int element);
};

void SDLL :: Insert(int value)
{
    node *n = new node(value);
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
    node* temp = head->next;
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

bool SDLL :: Delete(int value)
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
   node* temp=head->next;
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

void SDLL :: traverse_forward()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void SDLL :: traverse_backward()
{
    node* temp = tail;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

node* SDLL :: search(int element)
{
    if(head->data>element) return NULL;
    if(tail->data<element) return NULL;
    node* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==element) return temp;
        if(temp->data>element) return NULL;
        temp=temp->next;
    }
}

int main()
{
cout<<endl;

    SDLL l1;
    l1.Insert(10);
    l1.Insert(30);
    l1.Insert(20);
    l1.Insert(40);
    l1.Insert(22);
    cout<<"--- First List ---"<<endl;
    cout<<"Forward traversing  : ";
    l1.traverse_forward();
    cout<<"Backward traversing : ";
    l1.traverse_backward();
    node* temp=l1.search(15);
    if(temp!=NULL)
    cout<<temp->data<<endl;
    cout<<"Forward traversing  : ";
    l1.traverse_forward();
    cout<<"Backward traversing : ";
    l1.traverse_backward();



return 0;
}