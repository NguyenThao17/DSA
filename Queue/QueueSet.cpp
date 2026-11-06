#include <iostream>
#include <string>
using namespace std;

// Implement an integer queue yourself (circular array or linked list, FIFO,
// do NOT use std::queue) providing the following operations:
//   void enqueue(int x)   - add x to the back
//   bool emptyQueue()     - return true if the queue is empty
//   int  frontValue()     - return the front value (the queue is non-empty)
//   int  dequeue()        - remove and return the front value (the queue is non-empty)
//   int  sizeQueue()      - return the number of elements currently in the queue
struct Node
{
    int key;
    Node* pNext;
};

struct list{
    Node* pHead;
    Node* pTail;
};

Node* CreateNode(int x)
{
    Node* p=new Node;
    if(p==NULL) exit(1);
    p->key=x;
    p->pNext=NULL;
    return p;
}

void AddTail(list& l, Node* p)
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

void enqueue(int x)
{
    if(n==0)
    {
        l.pHead=NULL;
        l.pTail=NULL;
    }
    Node* p=CreateNode(x);
    AddTail(l,p);
    n++;
}

bool emptyQueue()
{
    return n==0;
}

int dequeue()
{
    int x=l.pHead->key;
    n--;
    if(n>1)
        l.pHead=l.pHead->pNext;
    else if(n==1)
        l.pHead=l.pTail;
    else 
    {
        l.pHead=NULL;
        l.pTail=NULL;
    }
    return x;
}
int frontValue()
{
    int x=l.pHead->key;
    return x;
}
int sizeQueue()
{
    return n;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        string cmd;
        cin >> cmd;
        if (cmd == "ENQUEUE") {
            int x;
            cin >> x;
            enqueue(x);
        } else if (cmd == "DEQUEUE") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << dequeue() << '\n';
        } else if (cmd == "FRONT") {
            if (emptyQueue()) cout << "EMPTY\n";
            else cout << frontValue() << '\n';
        } else {
            cout << sizeQueue() << '\n';
        }
    }

    return 0;
}

