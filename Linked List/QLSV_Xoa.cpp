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

void NhapNgay(NGAY &);
void XuatNgay(NGAY );
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST );
void NhapDS(LIST &, int n);
bool Xoa_TheoHoTen(LIST &, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

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
    SINHVIEN a;
    NODE* p=new NODE;
    for(int i=0; i<n;i++)
    {
        NhapSinhVien(a);
        p=CreateNode(a);
        AddTail(L,p);
    }
}
bool Xoa_TheoHoTen(LIST &l, string a)
{
    if(l.pHead==NULL) return false;
    bool Xoa = false;
    while(l.pHead!=NULL&&l.pHead->key.HoTen==a)
    {
        NODE* temp=l.pHead;
        l.pHead=l.pHead->pNext;
        delete temp;
        Xoa=true;        
    }
    if(l.pHead==NULL)
    {
        l.pTail=NULL;
        return true;
    }
    NODE* p=l.pHead;
    while(p->pNext!=NULL){
        if(p->pNext->key.HoTen==a)
        {
            NODE* temp=p->pNext;
            p->pNext=temp->pNext;
            if(temp==l.pTail)
            {
                l.pTail=p;
            }
            delete temp;
            Xoa=true;
        }
        else
            p=p->pNext;
    }
    return Xoa;
}
