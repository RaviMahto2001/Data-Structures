#include<iostream>
using namespace std;

class node{
    private :
    int data;
    node *next;
    node(int value)
    {
        data=value;
        next=NULL;
    }
    
    friend class SLL;
};

class SLL
{
    private :
    node* head;
    public:
    SLL()
    {
        head=NULL;
    }
    void insertathead(int value);
    void insertattail(int value);
    void insertatpos(int pos,int value);
    bool deleteathead();
    bool deleteattail();
    bool deleteatpos(int pos);
    void traverse();
};

void SLL :: traverse()
{
    if(head==NULL)
    {
        cout<<"NULL";
        return;
    }
    node* temp=head;
    do
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }while(temp!=head);
    cout<<"head"<<endl;
}

void SLL :: insertathead(int value)
{
    node* n = new node(value);
    if(head==NULL)
    {
        n->next=n;
        head=n;
        return;
    }
    n->next = head;
    node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=n;
    head=n;
}

void SLL :: insertattail(int value)
{
    node* n = new node(value);
    node *temp = head;
    if(head==NULL)
    {
        head=n;
        n->next=head;
        return;
    }
    while(temp->next!=head)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next=head;
}

void SLL :: insertatpos(int pos,int value)
{
    if(pos<1) 
    {
        cout<<"error!! unexpected pos."<<endl;
        return;
    }
    if(head==NULL && pos>1)
    {
        cout<<"error!! pos is greater than the size of the list."<<endl;
        return;
    }
    if(pos==1)
    {
        insertathead(value);
        return;
    }
    node* n = new node(value);
    int j=1;
    node* temp=head;
    while(j!=pos-1 && temp->next!=head)
    {
        temp=temp->next;
        j++;
    }
    if(j!=pos-1)
    {
        cout<<"error!! pos is greater than size of list"<<endl;
        return;
    }
    n->next=temp->next;
    temp->next=n;
}

bool SLL :: deleteathead()
{
    if(head!=NULL)
    {
        node *todel=head;
        if(head->next!=head)
        {
            head=head->next;
            node* temp=head;
            while(temp->next!=todel)
                temp=temp->next;
            temp->next=head;
        }
        else
        {
            head=NULL;
        }
        delete todel;
    return true;
    }

return false;
}

bool SLL :: deleteattail()
{
    if(head==NULL) return false;
    if(head->next==head)
    {
        delete head;
        head=NULL;
        return true;
    }
    else
    {
        node* temp=head;
        while(temp->next->next!=head)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=head;
        return true;
    }
return false;
}

bool SLL :: deleteatpos(int pos)
{
    if(head==NULL)
    {
        return false;
    }
        
    if(pos==1) return deleteathead();
    node* temp=head;
    int j=1;
    while( j!=pos-1 && temp->next->next!=head )
    {
        temp=temp->next;
        j++;
    }
    if(j==pos-1)
    {
        if(temp->next==head)
        {
            cout<<"error!! pos is greater than the size of list."<<endl;
            return false;
        }
        else
        {
            node* todel=temp->next;
            temp->next=temp->next->next;
            delete todel;
            return true;
        }
    }
    else
    { 
        cout<<"error!! pos is greater than the size of list."<<endl;
        return false;
    }
}

int main()
{
    SLL l1;
    l1.insertathead(13);
    l1.insertattail(10);
    l1.insertattail(11);
    l1.insertattail(12);
    l1.traverse();
    l1.deleteatpos(2);
    l1.traverse();
}

