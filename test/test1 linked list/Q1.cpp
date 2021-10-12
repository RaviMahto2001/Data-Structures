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
    void display_odd_elements();
    void find_middle();
    double avg_list_elements();
    bool check_same_list(node* otherhead);
    static int size_of_list(node* temp)
    {
        int i=0;
        while(temp!=NULL)
        {
            i++;
            temp=temp->next;
        }
    return i;
    }
};

void DLL :: insert_at_head(int value)
{
    node *n = new node(value);
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

void DLL :: insert_at_pos(int pos,int value)
{
    // when pos is 1
    // head modification required.
   if(pos==1) {insert_at_head(value); return;}
   int j=1; // for current position
   node* temp=head;
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
        return;
    }
    n->prev=tail;
    tail->next=n;
    tail=n;
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
    head->prev=NULL;

return true;
}

bool DLL :: delete_from_pos(int pos)
{
    if(head==NULL || pos<1) return false;
    if(pos==1) return delete_from_head(); 
    int j=1; // to store current position
    node* temp=head;
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
    tail->next=NULL;

return true;
}

void DLL :: traverse_forward()
{
    node* temp = head;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void DLL :: traverse_backward()
{
    node* temp = tail;
    while(temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}

void DLL :: display_odd_elements()
{
    node* temp = head;
    int i=1;
    while(temp != NULL)
    {
        if(i%2!=0)
        {
        cout<<temp->data<<" ";
        }
        i++;
        temp = temp->next;
    }
}

void DLL :: find_middle()
{
    int size=size_of_list(head);
    int mid=size/2;
    int counter=0;
    node* temp=head;
    while(counter!=mid)
    {
        temp=temp->next;
        counter++;
    }

   cout<<"Middle element of list : "<<temp->data<<endl;
}

double DLL :: avg_list_elements()
{
    int s=0;
    double sum=0.0,avg=0.0;
    node* temp=head;
    while(temp!=NULL)
    {
        sum += temp->data;
        s++;
        temp=temp->next;
    }
    avg = sum/s;
    return avg;
}

bool DLL :: check_same_list(node* otherhead)
{
    node* temp1=head;
    node* temp2=otherhead;
    while(temp1!=NULL && temp2!=NULL)
    {
        if(temp1->data!=temp2->data) return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if(temp1==NULL && temp2==NULL)
        return true;
    else
        return false;
}

