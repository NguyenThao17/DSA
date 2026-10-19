

#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void quickSort(int a[], int l, int r)
{
    int mid=l+(r-l)/2;
    int x=a[mid];
    int i=l, j=r;
    while(i<=j)
    {
        while(a[i]<x)
        {
            i++;
        }
        while(a[j]>x)
        {
            j--;
        }
        if(i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
        }
    }
    if(i<r)
        quickSort(a,i,r);
    if(j>l)
        quickSort(a,l,j);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int* a = new int[n];
    for (int i = 0; i < n; i++) cin >> a[i];

    if (n > 0) quickSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
