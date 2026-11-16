#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int insertNode(Node* &root , Node* x)
{
    if(root!=NULL)
    {
        if(root->data==x->data) return 0;
        if(root->data >x->data) return insertNode(root->left,x);
        else return insertNode(root->right,x);
    }
    root =x;
    return 1; 
}
void inorder(Node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}
int findMax(Node* root)
{
    if(root==NULL) return 1;
    Node* p=root;
    while(p->right!=NULL)
    {
        p=p->right;
    }
    return p->data;
}
int findMin(Node* root)
{
    if (root==NULL) return -1;
    Node* p=root;
    while(p->left!=NULL)
    {
        p=p->left;
    }
    return p->data;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    Node* root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        insertNode(root, createNode(data));
    }
    cout<<findMin(root)<<" "<<findMax(root);
    return 0;
}
