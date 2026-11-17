#include<iostream>
using namespace std;

struct NODE
{
    int key;
    NODE* left;
    NODE* right;
};

typedef NODE* TREE;

void CreatTREE(TREE &T)
{
    T=NULL;
}

NODE* CreatNode(int x)
{
    NODE* p= new NODE;
    if(p==NULL) exit(1);
    p->key=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}
bool insert(TREE &T, int x)
{
    if(T!=NULL)
    {
        if(T->key==x) return false;
        else if(T->key<x) return insert (T->right, x);
        else return insert(T->left, x);
    }
    T=CreatNode(x);
    return true;
}
void inorder(TREE T)
{
    if(T!=NULL)
    {
        inorder(T->left);
        cout<<T->key<<" ";
        inorder(T->right);
    }
}
void ThayThe(TREE &q,TREE &p)
{
    if(q->left!=NULL)
    {
        ThayThe(q->left,p);
    }
    else{
        p->key=q->key;
        p=q;
        q=q->right;
    }
}

bool Delete(TREE &T, int x)
{
    if(T!=NULL)
    {
        if(T->key>x) return Delete(T->left,x);
        else if(T->key<x) return Delete (T->right,x);
        else{
            NODE* tmp=T;
            if(T->left==NULL) T=T->right;
            else
            {
                if(T->right==NULL) T=T->left;
                else ThayThe(T->right,tmp);
            }

            delete tmp;
            return true;

        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    TREE T;
    CreatTREE(T);
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        insert(T,x);
    }
    int d;
    cin>>d;
    for(int i=0; i<d; i++)
    {
        int x;
        cin>>x;
        Delete(T, x);
    }
    inorder(T);
    cout<<endl;
}