
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void SapXep(LIST &);

int main() {
    LIST L;

    int n;
    cin >> n ;
    NhapDS(L, n);
    SapXep(L);
    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}
NODE* CreateNode(SINHVIEN x)
{
    NODE* p;
    p= new NODE;
    if(p==NULL) exit(1);
    p->key= x;
    p->pNext=NULL;
    return p;
};
void CreateEmptyList(LIST &L)
{
    L.pHead = NULL;
    L.pTail=NULL;
}
void AddTail(LIST& l, NODE* p)
{
    if(l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=l.pHead;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}
void XuatDS(LIST L)
{
    NODE* p=L.pHead;
    if(p==NULL)
    {
        cout<<"Empty List.";
        return;
    }
    while(p!=NULL)
    {
        XuatSinhVien(p->key);
        cout<<endl;
        p=p->pNext;
    }
}
void NhapDS(LIST &L, int n)
{
    CreateEmptyList(L);
    SINHVIEN sv;
    for(int i=0; i<n; i++)
    {
        NhapSinhVien(sv);
        AddTail(L,CreateNode(sv));
    }
}
void SapXep(LIST &l)
{
    if(l.pHead==NULL)
    {
        return;
    } 
    NODE* p=l.pHead;
    while(p->pNext!=NULL)
    {
        NODE* max=p;
        NODE* q=p->pNext;
        while(q!=NULL)
        {
            if(max->key.MASV<q->key.MASV)
            {
                max=q;
            }
            q=q->pNext;
        }
        SINHVIEN temp=max->key;
        max->key=p->key;
        p->key=temp;
        p=p->pNext;
    }
}
