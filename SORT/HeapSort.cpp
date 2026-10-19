#include<iostream>
using namespace std;

void Heapify(int a[], int left, int right)
{
    int i=left;
    int x=a[i];
    int pos=i*2+1;
    while(pos<=right)
    {
        if(pos<right)
        {
            if(a[pos]<a[pos+1])
                pos++;
        }
        if(a[pos]>x)
        {
            a[i]=a[pos];
            a[pos]=x;
        }
        i=pos;
        x=a[i];
        pos=i*2+1;
    }
}

void BuilHeap(int a[], int n)
{
    int mid=n/2 -1;
    while(mid>=0)
    {
        Heapify(a,mid,n-1);
        mid--;
    }
}
void Swap(int&a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
int main()
{
    int n,a[200];
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Mang truoc khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n\n";
    cout<<"Sap xep:\n";
    BuilHeap(a,n);
    cout<<"Mang sau khi BuildHeap: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<"Swap "<<a[0]<<" va "<<a[n-1];
    cout<<endl<<endl;
    Swap(a[0],a[n-1]);
    for(int i=n-1; i>=1; i--)
    {
        Heapify(a,0,i-1);
        cout<<"Mang sau khi heapify voi n = "<<i<<": ";
        for(int j=0; j<n; j++) 
        {
            if(j==i)
            {
                cout<<"| ";
            }
            cout<<a[j]<<" ";
        }
        cout<<endl;
        if(i>=2)
        {
            cout<<"Swap "<<a[0]<<" va "<<a[i-1]<<endl;
            Swap(a[0],a[i-1]);
            cout<<endl;
        } 
    }
    cout<<"Mang sau khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}   