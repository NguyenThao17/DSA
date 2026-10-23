#include<iostream>
using namespace std;

void quickSort(int a[], int l, int r, int n)
{
    cout<<"Truoc: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n";
    int i=l,j=r;
    int mid=i+(j-i)/2;
    int x=a[mid];
    cout<<"Left="<<i<<" - Right="<<j<<" - Pivot="<<x<<endl;
    while(i<=j)
    {   
        while (a[i]<x)
        {
            i++;
        }
        while (a[j]>x)
        {
            j--;
        }
        if(i<=j)
        {
            int temp=a[i];
            a[i]=a[j];
            a[j]=temp;
            i++;
            j--;
        }
    }
    cout<<"Sau: ";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<endl;
    if(l<j) quickSort(a, l, j, n);
    if(i<r) quickSort(a, i, r, n);
} 

int main()
{
    int n, a[200];
    cin>>n; 
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Mang truoc khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n\n";
    cout<<"Sap xep:\n";
    quickSort(a, 0, n-1, n);
    cout<<"Mang sau khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}