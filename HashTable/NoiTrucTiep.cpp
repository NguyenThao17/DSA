#include<iostream>
using namespace std;
#define M 11

struct Node{
    int key;
    Node* next;
};
typedef Node* HT[M];

void Init (HT &H)
{
    for(int i=0; i<M; i++)
    {
        H[i]=NULL;
    }
}
Node* Search(HT H, int key)
{
    int i=key%M;
    Node* p=H[i];
    while(p!=NULL&&p->key!=key)
    {
        p=p->next;
    }
    return p;
}
Node* CreatNode(int key)
{
    Node* p=new Node;
    if(p==NULL) exit(0);
    p->key=key;
    p->next=NULL;
    return p;
}

bool Insert(HT &H, int key)
{
    int i=key%M;
    Node* p=H[i];
    while(p!=NULL)
    {
        if(p->key==key) return false;
        p=p->next;
    }
    Node* q=CreatNode(key);
    q->next=H[i];
    H[i]=q;
    return true;
}
bool Remove (HT &H, int key)
{
    int i=key%M;
    Node* p=H[i];
    if(p==NULL) return false; //kiểm tra bucket rỗng tránh lỗi truy cập null
    if(p->key==key)
    {
        H[i]=H[i]->next;
        delete p;
        return true;
    }
    while(p->next!=NULL)
    {
        if(p->next->key==key)
        {
            Node* del=p->next; //giữa địa chỉ nút cần xóa
            p->next=del->next;
            delete del;
            return true;
        }
        p=p->next;
    }
    return false;

}
void PrintTable(HT H)
{
    for(int i=0; i<M; i++)
    {
        Node* p=H[i];
        while(p!=NULL)
        {
            cout<<p->key<<" ";
            p=p->next;
        }
        cout<<endl;
    }
}
void Destroy (HT &H)
{
    for(int i=0; i<M; i++)
    {
        while(H[i]!=NULL)
        {
            Node* del=H[i];
            H[i]=H[i]->next;
            delete del;
        }
    }

}
