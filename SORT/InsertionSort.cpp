#include<iostream>
using namespace std;

int main(){
    int n,a[200];
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    cout<<"Mang truoc khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;
    cout<<endl;
    cout<<"Sap xep:\n";
    for(int j=1; j<n; j++)
    {
        int x=a[j];
        cout<<"i = "<<j<<endl;
        cout<<"Mang truoc khi xu ly: ";
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<endl;
        cout<<"Phan tu dang xet A["<<j<<"] = "<<x<<endl;
        int pos=j-1;
        while(pos>=0&&a[pos]>x)
        {
            a[pos+1]=a[pos];
            pos--;
        }
        a[pos+1]=x;
        cout<<"Chen "<<x<<" vao vi tri k = "<<pos+1<<endl;
        cout<<"Mang sau khi xu ly: ";
        for(int i=0; i<n; i++) cout<<a[i]<<" ";
        cout<<endl;
        cout<<endl;
    }
    cout<<"Mang sau khi sap xep:\n";
    for(int i=0; i<n; i++) cout<<a[i]<<" ";
}