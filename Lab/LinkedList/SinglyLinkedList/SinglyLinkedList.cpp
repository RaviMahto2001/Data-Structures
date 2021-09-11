#include<iostream>
using namespace std;

class node{
    public :
    int data;
    node *next;
    node(int value)
    {
        data=value;
        next=NULL;
    }
};

class SinglyLinkedList
{
    public :
    node* head;
    SinglyLinkedList()
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
    node* search(int element);
    void concatenate(node* head1,node* head2);
};

void SinglyLinkedList :: traverse()
{
    node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

node* SinglyLinkedList :: search(int element)
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

void SinglyLinkedList :: insertathead(int value)
{
    node* n = new node(value);
    n->next = head; head = n;
}

void SinglyLinkedList :: insertattail(int value)
{
    node* n = new node(value);
    node *temp = head;
    if(head==NULL)
    {
        head=n; return;
    }
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

void SinglyLinkedList :: insertatpos(int pos,int value)
{
    if(pos==1)
    {
        insertathead(value); return;
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

bool SinglyLinkedList :: deleteathead()
{
    if(head!=NULL)
    {
        node *temp=head;
        if(head->next!=NULL)
        {
            head=head->next;
        }
        else head=NULL;
        delete temp;
    return true;
    }

return false;
}

bool SinglyLinkedList :: deleteattail()
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

bool SinglyLinkedList :: deleteatpos(int pos)
{
    if(head==NULL)
        return false;
    else
    {
        if(pos==1) return deleteathead();
        node *temp=head;
        int j=1;
        while(temp!=NULL && j!=pos-1)
        {
            temp=temp->next; j++;
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
            else return false;
        }
        else return false;
    }
return true;
}

void SinglyLinkedList :: concatenate(node* head1,node* head2)
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

SinglyLinkedList l1;
SinglyLinkedList l2;
SinglyLinkedList l3;

void ListCreatingMenu(SinglyLinkedList &l);
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
        case 3 :    l3.concatenate(l1.head,l2.head);
                    cout<<"--- List 3 ---"<<endl;
                    l3.traverse();
                    system("pause");
                    system("cls");
                    Menu();
                    break;
        case 4 :    exit(0);
    }

}

void ListCreatingMenu(SinglyLinkedList &l)
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
    cout<<"9. Go Back "<<endl;
    cout<<"Enter your choice : ";
    int choice=0;
    cin>>choice;
    if(choice>9 || choice<1)
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
        case 9: system("cls");
                Menu();
                break;
    }
}

int main()
{
    Menu();
    return 0;
}
