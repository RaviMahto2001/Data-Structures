#include<iostream>
using namespace std;

template <class T>
class node{
    private:
    int data;
    node<T>* next;
    node<T>* prev;
    public:
    node(T value)
    {
        data=value;
        next=NULL;
        prev=NULL;
    }

    template <class X> friend class DLL; // DLL will now have access to 
                      // private members of node directly
};

template <class T>
class DLL{
    private:
    node<T>* head;
    node<T>* tail;
    public:
    DLL()
    {
        head=NULL;
        tail=NULL;
    }
    node<T>* gethead() {return head;}
    node<T>* gettail() {return tail;}
    void insert_at_head(T value);
    void insert_at_pos(int pos ,T value);
    void insert_at_tail(T value);
    bool delete_from_head();
    bool delete_from_pos(int pos);
    bool delete_from_tail();
    void traverse_forward();
    void traverse_backward();
    node<T>* search(T element);
    void reverseDLL();
    void concatenate(node<T>* head1, node<T>*head2);
};

template <class T>
void DLL<T> :: insert_at_head(T value)
{
    node<T>* n = new node<T>(value);
    if(head==NULL)
    {
        tail=n;
        head=n;
        return;
    }
    n->next=head;
    head->prev=n;
    head=n;
}

template <class T>
void DLL<T> :: insert_at_pos(int pos,T value)
{
    // when pos is 1
    // head modification required.
   if(pos==1) {insert_at_head(value); return;}
   int j=1; // for current position
   node<T>* temp=head;
   while(j!=pos-1 && temp->next!=NULL) //to stop at (pos-1)th node 
   {
       temp=temp->next;
       j++;
   }
   if(j==pos-1)//if above loop exit by 1st condition
   {
       if(temp->next==NULL) //if currently at end of list this means
                            // we need to insert at end of list.
                            // tail modification required.
       {
           insert_at_tail(value);
       }
       else // we need to insert somewhere in the mid of list
            // no need to modify head or tail.
       {
           node<T>* n = new node<T>(value);
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

template <class T>
void DLL<T> :: insert_at_tail(T value)
{
    node<T>* n = new node<T>(value);
    if(head==NULL)
    {
        head=n;
        tail=n;
        return;
    }
    n->prev=tail;
    tail->next=n;
    tail=n;
}

template <class T>
bool DLL<T> :: delete_from_head()
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
    head->prev=NULL;

return true;
}

template <class T>
bool DLL<T> :: delete_from_pos(int pos)
{
    if(head==NULL || pos<1) return false;
    if(pos==1) return delete_from_head(); 
    int j=1; // to store current position
    node<T>* temp=head;
    // to reach at the position pos
    while(j!=pos && temp->next!=NULL)
    {
        temp=temp->next;
        j++;
    }
    if(j==pos)
    {
        //pos is the last position in the list.
        if(temp->next==NULL)
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

template <class T>
bool DLL<T> :: delete_from_tail()
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
    tail->next=NULL;

return true;
}

template <class T>
void DLL<T> :: traverse_forward()
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
void DLL<T> :: traverse_backward()
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
node<T>* DLL<T> :: search(T element)
{
    node<T>* temp=head;
    while(temp!=NULL)
    {
        if(temp->data==element)
        {
            return temp;
        }
        temp=temp->next;
    }
return NULL;
}

template <class T>
void DLL<T> :: concatenate(node<T>* head1, node<T>* head2)
{
    node<T>* x=NULL; //for traversing new list
    node<T>* temp;   //for traversing parameters list
    if(head1!=NULL)
    {
        // written outside while loop because head need to be modified
        node<T>* n = new node<T>(head1->data);
        head=n;
        x=n;
        temp=head1->next; // first node handled already above
        while(temp!=NULL)
        {
            node<T>* n = new node<T>(temp->data);
            n->prev=x;
            x->next=n;
            x=n;
            temp=temp->next;
        }
    }
    
    if(head2!=NULL)
    {
        temp=head2;
        // if x is NULL that means list 1 is empty
        // new list head need to be modified
        if(x==NULL)
        {
            node<T>* n = new node<T>(head2->data);
            head=n;
            x=n;
            temp=temp->next; // first node of list 2 already handled above
        }
        while(temp!=NULL)
        {
            node<T>* n = new node<T>(temp->data);
            n->prev=x;
            x->next=n;
            x=n;
            temp=temp->next;
        }
    }
    // if head2 is NULL then in that case also x is pointing to 
    // the last node created 
    tail=x; // assigning x to tail which is pointing to last node
}

template <class T>
void DLL<T> :: reverseDLL()
{
    if(head==tail) return;
    node<T>* temp=head; //for traversing
    node<T>* xyz; //for help in swaping
    //for swaping next and prev pointers 
    while(temp!=NULL)
    {
        xyz=temp->next;
        temp->next=temp->prev;
        temp->prev=xyz;
        temp=temp->prev; 
    }
    //swapping head and tail
    xyz=head;
    head=tail;
    tail=xyz;   
}

int main()
{
cout<<endl;
    DLL<int> d1;
    d1.insert_at_head(23);
    d1.insert_at_head(25);
    d1.insert_at_tail(10);
    d1.insert_at_tail(14);
    d1.insert_at_tail(20);
    cout<<"--- First List ---"<<endl;
    cout<<"Forward traversing  : ";
    d1.traverse_forward();
    cout<<"Backward traversing : ";
    d1.traverse_backward();
cout<<endl;
    DLL<int> d2;
    d2.insert_at_tail(3);
    d2.insert_at_tail(4);
    d2.insert_at_tail(2);
    d2.insert_at_head(9);
    d2.insert_at_head(7);
    cout<<"--- Second List ---"<<endl;
    cout<<"Forward traversing  : ";
    d2.traverse_forward();
    cout<<"Backward traversing : ";
    d2.traverse_backward();
cout<<endl;
    DLL<int> d3;
    d3.concatenate(d1.gethead(),d2.gethead());
    cout<<"--- Concatenated List ---"<<endl;
    cout<<"Forward traversing  : ";
    d3.traverse_forward();
    cout<<"Backward traversing : ";
    d3.traverse_backward();
cout<<endl;
return 0;
}