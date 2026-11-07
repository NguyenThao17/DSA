
#include <iostream>
#include <string>
using namespace std;

// Implement a queue of document names yourself (array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(const string& name) - add a document name to the back
//   bool emptyQueue()                - return true if the queue is empty
//   string dequeue()                 - remove and return the front document name (queue is non-empty)
struct node{
    string key;
    node* pNext;
};
struct list{
    node* pHead;
    node* pTail;
};
node* CreateNode(string a)
{
    node* p=new node;
    if(p==NULL) exit(1);
    p->key=a;
    p->pNext=NULL;
    return p;
}
void addTail(list& l, node* p)
{
    if(l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else{
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
int n=0;
list l;
void enqueue(const string& name)
{
    if(n==0)
    {
        l.pHead=NULL;
        l.pTail=NULL;
    }
    node* p=CreateNode(name);
    addTail(l,p);
    n++;
}
bool emptyQueue(){
    return n==0;
}
string dequeue()
{
    string x=l.pHead->key;
    n--;
    if(n>=1)
    {
        l.pHead=l.pHead->pNext;
    }
    else 
    {
        l.pHead=NULL;
        l.pTail=NULL;
    }
    return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ADD") {
            string name;
            cin >> name;
            enqueue(name);
        } else {
            if (emptyQueue()) cout << "NO DOCUMENT\n";
            else cout << dequeue() << '\n';
        }
    }

    return 0;
}
