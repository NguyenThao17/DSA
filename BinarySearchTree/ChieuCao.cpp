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

int height(TREE T)
{
    if(T!=NULL)
    {
        return 1 + max(height(T->left),height(T->right));
    }
    return -1;
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
    cout<<height(T);

}