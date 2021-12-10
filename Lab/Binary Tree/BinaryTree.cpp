#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class BTNode
{
    public:
    T info;
    BTNode<T> *lchild;
    BTNode<T> *rchild;
    BTNode(T x)
    {
        info = x;
        lchild = NULL;
        rchild = NULL;
    }
};

template <class T>
void Preorder(BTNode<T> *p)
{
    if (p != NULL)
    {
        cout << p->info << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

template <class T>
void Inorder(BTNode<T> *p)
{
    if (p != NULL)
    {
        Inorder(p->lchild);
        cout << p->info << " ";
        Inorder(p->rchild);
    }
}

template <class T>
void Postorder(BTNode<T> *p)
{
    if (p != NULL)
    {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->info << " ";
    }
}

template <class T>
void PreorderDFT_Iterative(BTNode<T> *root)
{
    cout << "Iterative Preorder Traversal" << endl;
    stack<BTNode<T> *> st;
    BTNode<T> *p = root;
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
void InorderDFT_Iterative(BTNode<T> *root)
{
    cout << "Iterative Inorder Traversal" << endl;
    stack<BTNode<T> *> st;
    BTNode<T> *p = root;
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
void PostorderDFT_Iterative(BTNode<T> *root)
{
    cout << "Iterative Postorder Traversal" << endl;
    stack<BTNode<T> *> st;
    BTNode<T> *p = root, *q = root;
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
void MirrorBT(BTNode<T>* oroot, BTNode<T>*& mroot)
{
    if(oroot==NULL)
    {
        mroot = NULL;
        return;
    }

    BTNode<T>* n = new BTNode<T>(oroot->info);
    mroot = n;
    MirrorBT(oroot->lchild,mroot->rchild);
    MirrorBT(oroot->rchild,mroot->lchild);
}

template <class T>
bool TestBST(BTNode<T>* node, int min, int max)
{
    if(node == NULL)
        return true;
    if(node->info < min || node->info > max)
        return false;

    return (TestBST(node->lchild,min,node->info) && TestBST(node->rchild,node->info,max));
}

template <class T>
int height(BTNode<T>* temp)
{
    if(temp == NULL)
        return -1;

    int lh = 1 + height(temp->lchild);
    int rh = 1 + height(temp->rchild);

    return max(lh,rh);
}

template <class T>
int countnodes(BTNode<T>* temp)
{
    if(temp == NULL)
        return 0;
    return 1 + countnodes(temp->lchild) + countnodes(temp->rchild);
}

template <class T>
int countrightchildren(BTNode<T>* temp)
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
int countleaves(BTNode<T>* temp)
{
    if(temp == NULL)
        return 0;

    if(temp->lchild == NULL && temp->rchild == NULL)
        return 1;
    
    return countleaves(temp->lchild) + countleaves(temp->rchild);
}

template <class T>
void DeleteLeaves(BTNode<T>* &node)
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

int main()
{
    BTNode<int> *n1 = new BTNode<int>(15);
    BTNode<int> *n2 = new BTNode<int>(20);
    BTNode<int> *n3 = new BTNode<int>(10);
    BTNode<int> *n4 = new BTNode<int>(5);
    BTNode<int> *n5 = new BTNode<int>(55);

    n1->lchild = n3;
    n1->rchild = n2;
    n3->lchild = n4;
    n3->rchild = n5;
    
    BTNode<int> *mirror;
/*
            15
          /   \
        10      20 
      /   \       
    5     55
LVR
VLR
LRV
*/
    Inorder(n1);
    cout<<endl;

    MirrorBT(n1,mirror);

    Inorder(mirror);
    // cout<<endl;

   // cout<<TestBST(n1,INT_MIN,INT_MAX);

}