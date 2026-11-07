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
void ChenGiam(LIST &, SINHVIEN);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

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
    NODE* p=new NODE;
    if(p==NULL) exit(1);
    p->key=x;
    p->pNext=NULL;
    return p;
}
void CreateEmptyList(LIST &L){
    L.pHead=NULL;
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
        cout<<"Empty List";
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
    SINHVIEN a;
    NODE* p=new NODE;
    for(int i=0; i<n;i++)
    {
        NhapSinhVien(a);
        p=CreateNode(a);
        AddTail(L,p);
    }
}
void ChenGiam(LIST &l, SINHVIEN a)
{
    NODE* q=CreateNode(a);
    if(l.pHead==NULL)
    {
        l.pHead=l.pHead=q;
        return;
    }
    NODE* p=l.pHead;
    if(p->key.MASV<a.MASV)
    {
        q->pNext=p;
        l.pHead=q;
    }
    else
    {
        while(p->pNext!=NULL&&p->pNext->key.MASV>a.MASV)
        {
            p=p->pNext;
        }
        q->pNext=p->pNext;
        p->pNext=q;
        if(p==l.pTail)
            l.pTail=p;
    }
}
