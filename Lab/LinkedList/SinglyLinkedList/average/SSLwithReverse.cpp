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
    public :
    SLL()
    {
        head=NULL;
    }
    node* gethead()
    {
        return head;
    }
    void insertathead(int value);
    void insertattail(int value);
    void insertatpos(int pos,int value);
    bool deleteathead();
    bool deleteattail();
    bool deleteatpos(int pos);
    void traverse();
    node* search(int element);
    void concatenate(node* head1,node* head2);
    void reverseSLL();
};

void SLL :: traverse()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* SLL :: search(int element)
{
    node* temp=head;
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

void SLL :: insertathead(int value)
{
    node* n = new node(value);
    n->next = head;
    head = n;
}

void SLL :: insertattail(int value)
{
    node* n = new node(value);
    node *temp = head;
    if(head==NULL)
    {
        head=n;
        return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void SLL :: insertatpos(int pos,int value)
{
    if(pos==1)
    {
        insertathead(value);
        return;
    }
    node* n = new node(value);
    int j=1;
    node* temp=head;
    while(j!=pos-1 && temp->next!=NULL)
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
        node *temp=head;
        if(head->next!=NULL)
        {
            head=head->next;
        }
        else
        {
            head=NULL;
        }
        delete temp;
    return true;
    }

return false;
}

bool SLL :: deleteattail()
{
    if(head->next==NULL)
    {
        node* temp = head;
        head=NULL;
        delete temp;
        return true;
    }
    else
    {
        node* temp=head;
        node* x;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        x=temp->next;
        temp->next=NULL;
        delete x;
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
    else
    {
        if(pos==1) return deleteathead();
        node *temp=head;
        int j=1;
        while(temp!=NULL && j!=pos-1)
        {
            temp=temp->next;
            j++;
        }
        if(j==pos-1)
        {
            if(temp!=NULL)
            {
                if(temp->next!=NULL)
                {
                    if(temp->next->next!=NULL)
                    {
                        node* x;
                        x=temp->next;
                        temp->next=temp->next->next;
                        delete x;
                    }
                    else return deleteattail();
                }
                else return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
return true;
}

void SLL :: concatenate(node* head1,node* head2)
{
    node*temp; node*x;
    if(head1!=NULL)
    {
    temp=head1;
    node* n = new node(temp->data);
    temp=temp->next; head=n; x=n;
    while(temp!=NULL)
    {
        node* n = new node(temp->data);
        x->next=n; x=n;
        temp=temp->next;
    }
    }
    else
    {
        if(head2==NULL) return;
    }
    if(head2!=NULL)
    {
    temp=head2;
    if(head==NULL)
    {
        node* n = new node(temp->data);
        head=n;
        x=n;
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        node* n = new node(temp->data);
        x->next=n;
        x=n;
        temp=temp->next;
    }
    }
}

void SLL :: reverseSLL()
{
if(head == NULL) return; // no element 
if(head->next == NULL) return; // one element

node* temp=head->next; //for traversing
node* prev=head; //for assining
node* xyz;
while(temp!=NULL)
{
    xyz=temp;
	temp = temp->next;
	xyz->next = prev;
	prev = xyz;
}
head->next=NULL;
head = prev;
}

SLL l1;
SLL l2;
SLL l3;

void ListCreatingMenu(SLL &l);
void Menu();

void Menu()
{
    cout<<"--- Menu ---"<<endl;
    cout<<"1. Perform Operation on List 1 "<<endl;
    cout<<"2. Perform Operation on List 2 "<<endl;
    cout<<"3. Concatenate List 1 and List 2 in List3 "<<endl;
    cout<<"4. Exit "<<endl;
    int choice=0;
    cout<<"Enter your choice : ";cin>>choice;
    if(choice>4 || choice<1)
    {
        cout<<"wrong choice!! try again..."<<endl;
        system("pause");
        system("cls");
        Menu();
    }
    switch(choice)
    {
        case 1 :    ListCreatingMenu(l1);
                    system("pause");
                    system("cls");
                    Menu();
                    break;
        case 2 :    ListCreatingMenu(l2);
                    system("pause");
                    system("cls");
                    Menu();
                    break;
        case 3 :    l3.concatenate(l1.gethead(),l2.gethead());
                    cout<<"--- List 3 ---"<<endl;
                    l3.traverse();
                    system("pause");
                    system("cls");
                    Menu();
                    break;
        case 4 :    exit(0);
    }

}

void ListCreatingMenu(SLL &l)
{
    system("cls");
    cout<<"--- Operation Menu for List ---"<<endl;
    cout<<"1. Insert element at beginning of list "<<endl;
    cout<<"2. Insert element at end of list "<<endl;
    cout<<"3. Insert element at ith pos in the list "<<endl;
    cout<<"4. Delete element from beginning of list "<<endl;
    cout<<"5. Delete element from end of list "<<endl;
    cout<<"6. Delete element at ith position in list "<<endl;
    cout<<"7. Show List "<<endl;
    cout<<"8. Search for element in List "<<endl;
    cout<<"9. Reverse List"<<endl;
    cout<<"10. Go Back "<<endl;
    cout<<"Enter your choice : ";
    int choice=0;
    cin>>choice;
    if(choice>10 || choice<1)
    {
        cout<<"wrong choice!! try again..."<<endl;
        system("pause");
        system("cls");
        ListCreatingMenu(l);
    }
    int element,ch,pos;
    node* check;
    bool flag;
    switch (choice)
    {
        case 1: do{
                cout<<"Enter element : ";cin>>element;
                l.insertathead(element);
                cout<<"do you want to enter more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 2: do{
                cout<<"Enter element : ";cin>>element;
                l.insertattail(element);
                cout<<"do you want to enter more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 3: do{
                cout<<"Enter position : ";cin>>pos;
                cout<<"Enter element : ";cin>>element;
                l.insertatpos(pos,element);
                cout<<"do you want to enter more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 4: do{
                flag=l.deleteathead();
                if(flag==false)
                    cout<<"error! deleting element."<<endl;
                else
                    cout<<"deletion successful."<<endl;
                cout<<"do you want to delete more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 5: do{
                flag=l.deleteattail();
                if(flag==false)
                    cout<<"error! deleting element."<<endl;
                else
                    cout<<"deletion successful."<<endl;
                cout<<"do you want to delete more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 6: do{
                cout<<"Enter pos : ";cin>>pos;
                flag=l.deleteatpos(pos);
                if(flag==false)
                    cout<<"error! deleting element."<<endl;
                else
                    cout<<"deletion successful."<<endl;
                cout<<"do you want to delete more (1/0): ";cin>>ch;
                }while(ch!=0);
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 7: l.traverse();
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 8: cout<<"Enter the element to search : ";cin>>element;
                check = l.search(element);
                if(check==NULL)
                    cout<<"Element not found."<<endl;
                else
                    cout<<"Element found at address : "<<check<<endl;
                check=NULL;
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 9: l.reverseSLL();
                cout<<"list reversed successfully."<<endl;
                system("pause");
                system("cls");
                ListCreatingMenu(l);
                break;
        case 10: system("cls");
                Menu();
                break;
    }
}

int main()
{
    Menu();
    return 0;
}