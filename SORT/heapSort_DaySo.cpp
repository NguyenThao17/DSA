#include<iostream>
using namespace std;
void heapyfi(int a[], int l, int r)
{
    int i=l;
    int x=a[i];
    int pos=i*2+1;
    while(pos<=r)
    {
        if(pos<r)
        {
            if(a[pos]<a[pos+1])
            {
                pos++;
            }
        }
        if(a[pos]>x)
        {
            a[i]=a[pos];
            a[pos]=x;
            i=pos;
            x=a[i];
            pos=i*2+1;
        }
        else
            return;
    }
    
}

void CreateHeap(int a[], int n)
{
    int mid=n/2 -1;
    while(mid>=0)
    {
        heapyfi(a,mid,n-1);
        mid--;
    }
}

void HeapSort(int a[], int n)
{
    CreateHeap(a,n);
    for(int i=n-1; i>0; i--)
    {
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        heapyfi(a,0,i-1);
    }      
}


int main()
{
    int n, a[100000];
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    HeapSort(a,n);
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}