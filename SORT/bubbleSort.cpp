#include<iostream>
using namespace std;

void bubbleSort(int a[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=n-1; j>i; j--)
        {
            if(a[j]<a[j-1])
            {
                int temp=a[j];
                a[j]=a[j-1];
                a[j-1]=temp;
            }
        }
    }
}

int main()
{
    int n, a[1000];
    cin>>n;
    for(int i =0; i<n; i++)
        cin>>a[i];
    bubbleSort(a,n);
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
}