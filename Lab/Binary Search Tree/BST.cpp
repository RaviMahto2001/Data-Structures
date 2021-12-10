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
    BST() { root = NULL;}

    //insert
    void insert(T x);

    //search
    BSTNode<T> *search(T el);

    //Traversal Functions
    void BFT();
    void Preorder(BSTNode<T> *);
    void Inorder(BSTNode<T> *);
    void Postorder(BSTNode<T> *);
    void PreorderDFT_Recursive();
    void InorderDFT_Recursive();
    void PostorderDFT_Recursive();
    void PreorderDFT_Iterative();
    void InorderDFT_Iterative();
    void PostorderDFT_Iterative();

    //Deleting Functions
    void DeleteByMerging(T);
    void DeleteByCopying(T);
    
    //height
    int height(BSTNode<T>*);

    //Delete all leaves
    void DeleteLeaves(BSTNode<T>* &node);

    //count no of node
    int countnodes(BSTNode<T>* temp);

    //count no of right children
    int countrightchildren(BSTNode<T>*);

    //count no of leaves
    int countleaves(BSTNode<T>*);

friend int main();
};

template <class T>
void BST<T>::DeleteLeaves(BSTNode<T>* &node)
{
    if(node == NULL)
        return;

    if(node->lchild == NULL && node->rchild == NULL)
    {
        delete node;
        node = NULL;
        return;
    }

    DeleteLeaves(node->lchild);
    DeleteLeaves(node->rchild);
}

template <class T>
int BST<T>::countleaves(BSTNode<T>* temp)
{
    if(temp == NULL)
        return 0;

    if(temp->lchild == NULL && temp->rchild == NULL)
        return 1;
    
    return countleaves(temp->lchild) + countleaves(temp->rchild);
}

template <class T>
int BST<T>::countrightchildren(BSTNode<T>* temp)
{
    int x=0;
    if (temp == NULL)
        return 0;
    
    x = countrightchildren(temp->lchild);

    if(temp->rchild != NULL)
        return 1 + x + countrightchildren(temp->rchild);

    return x;
}

template <class T>
int BST<T>::countnodes(BSTNode<T>* temp)
{
    if(temp == NULL)
        return 0;
    return 1 + countnodes(temp->lchild) + countnodes(temp->rchild);
}

//  there can be a method which doesn't require 
//  global h
template <class T>
int BST<T>::height(BSTNode<T>* temp)
{
    if(temp == NULL)
        return -1;

    int lh = 1 + height(temp->lchild);
    int rh = 1 + height(temp->rchild);

    return max(lh,rh);
}

/*
template <class T>
void BST<T>::height(BSTNode<T>* temp,int path)
{
    if(temp->lchild == NULL && temp->rchild == NULL)
    {
        if(h<path)
            h = path;
        return;
    }
    if(temp->lchild != NULL)
        height(temp->lchild,path+1);
    if(temp->rchild != NULL)
        height(temp->rchild,path+1);
}

template <class T>
int BST<T>::height_Recursive()
{
    if(root == NULL)
        return 0;
    height(root,0);
    return h;
}
*/

/*
template <class T>
int BST<T>::height_Iterative()
{

}
*/

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

    BSTNode<T> *&parent_todel_child = (parent_todel == NULL) ? root : (parent_todel->lchild == todel) ? parent_todel->lchild : parent_todel->rchild; //todel location in Parent

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

    BSTNode<T> *&parent_todel_child = (parent_todel == NULL) ? root : (parent_todel->lchild == todel) ? parent_todel->lchild : parent_todel->rchild; //todel location in Parent

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
void BST<T>::PreorderDFT_Recursive()
{
    cout << "Preorder Traversal" << endl;
    Preorder(root);
    cout << endl;
}
template <class T>
void BST<T>::InorderDFT_Recursive()
{
    cout << "Inorder Traversal" << endl;
    Inorder(root);
    cout << endl;
}
template <class T>
void BST<T>::PostorderDFT_Recursive()
{
    cout << "Postorder Traversal" << endl;
    Postorder(root);
    cout << endl;
}
template <class T>
void BST<T>::PreorderDFT_Iterative()
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
void BST<T>::InorderDFT_Iterative()
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
void BST<T>::PostorderDFT_Iterative()
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
    BST<int> t1;
/*  
   // BINARY SEARCH TREE 1
    t1.insert(12);
    t1.insert(33);
    t1.insert(33);
    t1.insert(1);
    t1.insert(8);
    t1.insert(3);
    t1.insert(40);
    t1.insert(27);
    t1.insert(20);
    t1.insert(78);
    t1.insert(15);
*/   

/*
    // BINARY SEARCH TREE 2
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
*/

    // Binary Search Tree 3
/*
    t1.insert(150);
    t1.insert(200);
    t1.insert(30);
    t1.insert(70);
    t1.insert(20);
    t1.insert(25);
    t1.insert(10);
    t1.insert(2);
    t1.insert(15);
    t1.insert(27);
    t1.insert(23);
    t1.insert(21);
    t1.insert(26);
    t1.insert(29);
    t1.insert(80);
    t1.insert(50);
    t1.insert(40);
    t1.insert(60);
    t1.insert(65);
    t1.insert(45);
    t1.insert(75);
    t1.insert(100);
*/
/*
// Test Tree
    t1.insert(15);
    t1.insert(10);
    t1.insert(20);
*/
    /*
    BSTNode<int> *x = t1.search(33);
    if (x == NULL)
    {
        cout << "ELement not found." << endl;
    }
    else
    {
        cout << "Element found at address " << x << " : " << x->info << endl;
    }
*/

    /*
    t1.BFT();

    t1.PreorderDFT_Recursive();
    t1.InorderDFT_Recursive();
    t1.PostorderDFT_Recursive();

    t1.PreorderDFT_Iterative();
    t1.PostorderDFT_Iterative();
*/

/*
    t1.InorderDFT_Iterative();

    t1.DeleteByMerging(30);

    t1.InorderDFT_Iterative();

    t1.DeleteByCopying(30);

    t1.InorderDFT_Iterative();
*/



}