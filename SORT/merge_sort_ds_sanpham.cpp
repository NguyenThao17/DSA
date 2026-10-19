#include <iostream>
#include <string>
using namespace std;

struct SanPham {
    int ma;
    string ten;
    int gia;
};

void merge(SanPham a[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    SanPham* L =new SanPham [n1];
    SanPham* R=new SanPham[n2];
    for(int i=0; i<n1; i++)
    {
        L[i]=a[l+i];
    }
    for(int i=0; i<n2; i++)
    {
        R[i]=a[mid+1+i];
    }
    int i=0, j=0,k=l;
    while(i<n1&&j<n2)
    {
        if(L[i].gia<R[j].gia||L[i].gia==R[j].gia&&L[i].ma<=R[j].ma)
        {
            a[k]=L[i];
            i++;
        }
       
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while (j<n2)
    {
        a[k]=R[j];
        j++;
        k++;
    }
    delete[] L;
    delete [] R;

}
void mergeSort(SanPham a[],int l,int r)
{
    if(l<r)
    {
        int mid=l+(r-l)/2;
        mergeSort(a,l, mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    SanPham* a = new SanPham[n];
    for (int i = 0; i < n; i++) cin >> a[i].ma >> a[i].ten >> a[i].gia;

    if (n > 0) mergeSort(a, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << a[i].ma << ' ' << a[i].ten << ' ' << a[i].gia << '\n';
    }
    return 0;
}
