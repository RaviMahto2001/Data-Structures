#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class BSTNode
{
private:
    T info;
    BSTNode<T> *lchild;
    BSTNode<T> *rchild;

public:
    BSTNode(T x)
    {
        info = x;
        lchild = NULL;
        rchild = NULL;
    }

    template <class U>
    friend class BST;
};

template <class T>
class BST
{
private:
    BSTNode<T> *root;

public:
    BST() { root = NULL; }

    BSTNode<T> *getroot() { return root; }

    //insert
    void insert(T x);

    //search
    BSTNode<T> *search(T el);

    //Traversal Functions
    void BFT();
    void Preorder(BSTNode<T> *);
    void Inorder(BSTNode<T> *);
    void Postorder(BSTNode<T> *);
    void Preorder_Iterative();
    void Inorder_Iterative();
    void Postorder_Iterative();

    //Deleting Functions
    void DeleteByMerging(T);
    void DeleteByCopying(T);

    //height
    int height(BSTNode<T> *);

    void SearchXreplaceY(T,T);
};

template <class T>
void BST<T>::SearchXreplaceY(T x,T y)
{
    this->DeleteByCopying(x);
    this->insert(y);
}

template <class T>
int BST<T>::height(BSTNode<T> *temp)
{
    if (temp == NULL)
        return -1;

    int lh = 1 + height(temp->lchild);
    int rh = 1 + height(temp->rchild);

    return max(lh, rh);
}

template <class T>
void BST<T>::DeleteByMerging(T el)
{
    /* Delete by Merging Using inorder predecessor */

    BSTNode<T> *temp = root;         //traversing pointer
    BSTNode<T> *todel = NULL;        //node to be deleted
    BSTNode<T> *parent_todel = NULL; //Parent of the node to be deleted

    // To find Parent_todel and todel
    while (temp != NULL)
    {
        if (temp->info == el)
        {
            todel = temp;
            break;
        }
        else if (el < temp->info)
        {
            parent_todel = temp;
            temp = temp->lchild;
        }
        else
        {
            parent_todel = temp;
            temp = temp->rchild;
        }
    }

    if (todel == NULL)
    {
        cout << "Element to delete doesn't exists in tree." << endl;
        return;
    }

    BSTNode<T> *&parent_todel_child = (parent_todel == NULL) ? root : (parent_todel->lchild == todel) ? parent_todel->lchild
                                                                                                      : parent_todel->rchild; //todel location in Parent

    //implementing deletion by merging

    if (todel->lchild == NULL) // todel has only left node or todel is leaf
    {
        parent_todel_child = todel->rchild;
    }
    else if (todel->rchild == NULL) // todel has only right node
    {
        parent_todel_child = todel->lchild;
    }
    else // todel has both lchild and rchild
    {
        temp = todel->lchild;
        while (temp->rchild != NULL)
        {
            temp = temp->rchild;
        }
        /*  Now temp is inorder predecessor/
            rightmost element of todel's leftsubtree*/

        /* 
            parent of todel child may be left or right child
            is modified to point to todel lchild
        */
        parent_todel_child = todel->lchild;
        temp->rchild = todel->rchild;
    }

    delete todel;
}

template <class T>
void BST<T>::DeleteByCopying(T el)
{
    /* Delete by Copying Using inorder predecessor */

    BSTNode<T> *temp = root;         //traversing pointer
    BSTNode<T> *todel = NULL;        //node to be deleted
    BSTNode<T> *parent_todel = NULL; //Parent of the node to be deleted
    BSTNode<T> *prev = NULL;

    // to find Parent_todel and todel
    while (temp != NULL)
    {
        if (temp->info == el)
        {
            todel = temp;
            break;
        }
        else if (el < temp->info)
        {
            parent_todel = temp;
            temp = temp->lchild;
        }
        else
        {
            parent_todel = temp;
            temp = temp->rchild;
        }
    }

    if (todel == NULL)
    {
        cout << "Element to delete doesn't exists in tree." << endl;
        return;
    }

    BSTNode<T> *&parent_todel_child = (parent_todel == NULL) ? root : (parent_todel->lchild == todel) ? parent_todel->lchild
                                                                                                      : parent_todel->rchild; //todel location in Parent

    //implementing deletion by Copying

    if (todel->lchild == NULL) // todel has only left node or todel is leaf
    {
        parent_todel_child = todel->rchild;
    }
    else if (todel->rchild == NULL) // todel has only right node
    {
        parent_todel_child = todel->lchild;
    }
    else // todel has both lchild and rchild
    {
        temp = todel->lchild;
        prev = todel;
        while (temp->rchild != NULL)
        {
            prev = temp;
            temp = temp->rchild;
        }
        /*  Now temp is inorder predecessor/
            rightmost element of todel's leftsubtree*/

        /* 
            parent of todel child (may be left or right child)
            is modified to point to todel lchild
        */

        if (prev == todel)
        {
            prev->lchild = temp;
        }
        else
        {
            todel->info = temp->info;
            prev->rchild = temp->lchild;
        }
        todel = temp;
    }

    delete todel;
}

template <class T>
void BST<T>::BFT()
{
    cout << "Breadth First Traversal" << endl;
    BSTNode<T> *p = root;
    queue<BSTNode<T> *> q;
    q.push(p);
    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout << p->info << " ";
        if (p->lchild)
            q.push(p->lchild);
        if (p->rchild)
            q.push(p->rchild);
    }
    cout << endl;
}

template <class T>
void BST<T>::Preorder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        cout << p->info << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

template <class T>
void BST<T>::Inorder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->info << " ";
        Inorder(p->rchild);
    }
}

template <class T>
void BST<T>::Postorder(BSTNode<T> *p)
{
    if (p != NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->info << " ";
    }
}

template <class T>
void BST<T>::Preorder_Iterative()
{
    cout << "Iterative Preorder Traversal" << endl;
    stack<BSTNode<T> *> st;
    BSTNode<T> *p = root;
    if (p != NULL)
    {
        st.push(p);
        while (!st.empty())
        {
            p = st.top();
            st.pop();
            cout << p->info << " ";
            if (p->rchild != NULL)
                st.push(p->rchild);
            if (p->lchild != NULL)
                st.push(p->lchild);
        }
    }
    cout << endl;
}

template <class T>
void BST<T>::Inorder_Iterative()
{
    cout << "Iterative Inorder Traversal" << endl;
    stack<BSTNode<T> *> st;
    BSTNode<T> *p = root;
    while (p != NULL)
    {
        while (p != NULL)
        {
            if (p->rchild != NULL)
                st.push(p->rchild);
            st.push(p);
            p = p->lchild;
        }

        p = st.top();
        st.pop();

        while (!st.empty() && p->rchild == NULL)
        {
            cout << p->info << " ";
            p = st.top();
            st.pop();
        }

        cout << p->info << " ";

        if (!st.empty())
        {
            p = st.top();
            st.pop();
        }
        else
            p = NULL;
    }
    cout << endl;
}

template <class T>
void BST<T>::Postorder_Iterative()
{
    cout << "Iterative Postorder Traversal" << endl;
    stack<BSTNode<T> *> st;
    BSTNode<T> *p = root, *q = root;
    while (p != NULL)
    {
        while (p->lchild != NULL)
        {
            st.push(p);
            p = p->lchild;
        }

        while (p->rchild == NULL || p->rchild == q)
        {
            cout << p->info << " ";
            q = p;
            if (st.empty())
            {
                cout << endl;
                return;
            }
            p = st.top();
            st.pop();
        }

        st.push(p);
        p = p->rchild;
    }
}

template <class T>
void BST<T>::insert(T x)
{
    BSTNode<T> *n = new BSTNode<T>(x);
    if (root == NULL)
    {
        root = n;
        return;
    }
    BSTNode<T> *temp = root;
    while (temp != NULL)
    {
        if (x < temp->info)
        {
            if (temp->lchild == NULL)
            {
                temp->lchild = n;
                return;
            }
            else
                temp = temp->lchild;
        }
        else if (x > temp->info)
        {
            if (temp->rchild == NULL)
            {
                temp->rchild = n;
                return;
            }
            else
                temp = temp->rchild;
        }
        else
        {
            return;
        }
    }
}

template <class T>
BSTNode<T> *BST<T>::search(T el)
{
    BSTNode<T> *temp = root;
    while (temp != NULL)
    {
        if (el < temp->info)
        {
            temp = temp->lchild;
        }
        else if (el > temp->info)
        {
            temp = temp->rchild;
        }
        else
        {
            return temp;
        }
    }
    return NULL;
}

int main()
{
    cout<<"\n---   Binary Search Tree   ---\n\n"<<endl;

    BST<int> t1;

    // BINARY SEARCH TREE
    t1.insert(15);
    t1.insert(2);
    t1.insert(7);
    t1.insert(6);
    t1.insert(10);
    t1.insert(20);
    t1.insert(17);
    t1.insert(18);
    t1.insert(25);
    t1.insert(23);
    t1.insert(8);
    t1.insert(3);
    t1.insert(21);

    //Breadth First Traversal
    t1.BFT();

    cout<<"\nPreorder Traversal"<<endl;
    t1.Preorder(t1.getroot());
    cout<<endl;
    cout<<"Inorder Traversal"<<endl;
    t1.Inorder(t1.getroot());
    cout<<endl;
    cout<<"Postorder Traversal"<<endl;
    t1.Postorder(t1.getroot());
    cout<<endl;

    cout<<"\nHeight of BST : "<<t1.height(t1.getroot())<<endl;

    t1.DeleteByCopying(20);
    cout<<"\nInorder Traversal"<<endl;
    t1.Inorder(t1.getroot());
    cout<<endl;

    int x,y;
    cout<<"\nEnter the element you want to search : "; cin>>x;
    cout<<"Enter the value to replace with  : "; cin>>y;
    t1.SearchXreplaceY(x,y);
    cout<<"Inorder Traversal"<<endl;
    t1.Inorder(t1.getroot());
    cout<<endl;
    cout<<endl;

}