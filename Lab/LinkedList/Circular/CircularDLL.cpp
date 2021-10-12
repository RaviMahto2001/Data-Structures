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

    friend class DLL; // DLL will now have access to 
                      // private members of node directly
};

class DLL{
    private:
    node* head;
    node* tail;
    public:
    DLL()
    {
        head=NULL;
        tail=NULL;
    }
    node* gethead() {return head;}
    node* gettail() {return tail;}
    void insert_at_head(int value);
    void insert_at_pos(int pos ,int value);
    void insert_at_tail(int value);
    bool delete_from_head();
    bool delete_from_pos(int pos);
    bool delete_from_tail();
    void traverse_forward();
    void traverse_backward();
    node* search(int element);
};

void DLL :: insert_at_head(int value)
{
    node *n = new node(value);
    if(head==NULL)
    {
        tail=n;
        head=n;
        n->next=head;
        n->prev=tail;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
    tail->next=head;
    head->prev=tail;
}

void DLL :: insert_at_pos(int pos,int value)
{
    if(pos<1) {cout<<"error!! unexpected position"<<endl; return;}
    // when pos is 1
    // head modification required.
   if(pos==1) {insert_at_head(value); return;}
   int j=1; // for current position
   node* temp=head;
   while((j!=pos-1 && temp->next!=head)) //to stop at (pos-1)th node 
   {
       temp=temp->next;
       j++;
   }
   if(j==pos-1)//if above loop exit by 1st condition
   {
       if(temp->next==head) //if currently at end of list this means
                            // we need to insert at end of list.
                            // tail modification required.
       {
           insert_at_tail(value);
       }
       else // we need to insert somewhere in the mid of list
            // no need to modify head or tail.
       {
           node* n = new node(value);
           n->prev=temp;
           n->next=temp->next;
           temp->next->prev=n;
           temp->next=n;
       }
   }
   //if above loop exit by second condition and we are at lower 
   // position than required so need to return error.
   else
        cout<<"position is greater than size of list. "<<endl;
}

void DLL :: insert_at_tail(int value)
{
    node *n = new node(value);
    if(head==NULL)
    {
        head=n;
        tail=n;
        n->next=head;
        n->prev=tail;
        return;
    }
    n->prev=tail;
    tail->next=n;
    tail=n;
    tail->next=head;
    head->prev=tail;
}

bool DLL :: delete_from_head()
{
    if(head==NULL) return false;
    if(head==tail)
    {
        head=NULL;
        delete tail;
        tail=NULL;
        return true;
    }
    head=head->next;
    delete head->prev; //will only delete the contents at
                       // the location pointed by it.
    head->prev=tail;
    tail->next=head;

return true;
}

bool DLL :: delete_from_pos(int pos)
{
    if(head==NULL || pos<1) return false;
    if(pos==1) return delete_from_head(); 
    int j=1; // to store current position
    node* temp=head;
    // to reach at the position pos
    while(j!=pos && temp->next!=head)
    {
        temp=temp->next;
        j++;
    }
    if(j==pos)
    {
        //pos is the last position in the list.
        if(temp->next==head)
            return delete_from_tail();
        //else we need to delete somewhere in the mid of list.
        else
        {
            temp->next->prev=temp->prev;
            temp->prev->next=temp->next;
            delete temp;
            return true;
        }
    }

return false;
}

bool DLL :: delete_from_tail()
{
    if(tail==NULL) return false;
    if(head==tail)
    {
        head=NULL;
        delete tail;
        tail=NULL; 
        return true;
    }
    tail=tail->prev;
    delete tail->next; //will only delete the contents at
                       // the location pointed by it.
    tail->next=head;
    head->prev=tail;

return true;
}

void DLL :: traverse_forward()
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    node* temp = head;
    do
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }while(temp != head);
    cout<<"head"<<endl;
}

void DLL :: traverse_backward()
{
    if(tail==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    node* temp = tail;
    do
    {
        cout<<temp->data<<" -> ";
        temp = temp->prev;
    }while(temp != tail);
    cout<<"tail"<<endl;
}

node* DLL :: search(int element)
{
    if(head==NULL) return NULL;
    if(head->data==element) return head;
    node* temp=head->next;
    while(temp!=head)
    {
        if(temp->data==element)
        {
            return temp;
        }
        temp=temp->next;
    }
return NULL;
}

int main()
{
cout<<endl;
    DLL d1;
    d1.insert_at_head(23);
    d1.insert_at_head(25);
    d1.insert_at_tail(10);
    d1.insert_at_tail(14);
    d1.insert_at_tail(20);
    d1.insert_at_pos(3,200);
    cout<<"--- First List ---"<<endl;
    cout<<"Forward traversing  : ";
    d1.traverse_forward();
    cout<<"Backward traversing : ";
    d1.traverse_backward();
cout<<endl;
    DLL d2;
    d2.insert_at_tail(3);
    d2.insert_at_tail(4);
    d2.insert_at_tail(2);
    d2.insert_at_head(9);
    d2.insert_at_head(7);
    d2.insert_at_pos(2,100);
    d2.delete_from_pos(5);
    cout<<"--- Second List ---"<<endl;
    cout<<"Forward traversing  : ";
    d2.traverse_forward();
    cout<<"Backward traversing : ";
    d2.traverse_backward();
cout<<endl;
return 0;
}