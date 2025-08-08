#include <iostream>
#include <string>

using namespace std;
class NgayThang
{
private:
    int dd, mm, yy;
public:
    NgayThang();
    NgayThang(int d, int m, int y);
    void Xuat();
    void Sua(int &d, int &m, int &y);
};
NgayThang::NgayThang(): dd(1), mm(1), yy(1900) {}
NgayThang::NgayThang(int d, int m, int y): dd(1), mm(1), yy(1900) {
    Sua(d, m, y);
    this->dd = d;
    this->mm = m;
    this->yy = y;
}
void NgayThang::Xuat() {
    cout << this->dd << '/' << this->mm << '/' << this->yy;
}
void NgayThang::Sua(int &d, int &m, int &y) {
    if (y < 0)
        y = 0;
    if (m < 1)
        m = 1;
    else if (m > 12)
        m = 12;
    if (m == 2)
    {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
        {
            if (d > 29)
                d = 29;
        }
        else if (d > 28)
            d = 28;
    }
    if (d > 31 && (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12))
        d = 31;
    if (d > 30 && (m == 4 || m == 6 || m == 11))
        d = 30;
    if (d < 1)
        d = 1;
}
class SinhVien {
private:
    string MSSV;
    string HoTen;
    NgayThang NgaySinh;
    float DLT;
    float DTH;
public:
    SinhVien();
    SinhVien(string mssv);
    SinhVien(string mssv, string hoten, float dlt, float dth);
    SinhVien(string mssv, string hoten, float dlt, float dth, int d, int m, int y);
    SinhVien(string mssv, string hoten, float dlt, float dth, NgayThang ngaysinh);
    SinhVien(const SinhVien& copy);
    void Xuat();
};
SinhVien::SinhVien(): MSSV("xxxxxxx"), HoTen("xxxx"), DLT(0), DTH(0), NgaySinh(NgayThang()) {}
SinhVien::SinhVien(string mssv):
MSSV(mssv), HoTen("xxxx"), DLT(0), DTH(0), NgaySinh(NgayThang()) {}
SinhVien::SinhVien(string mssv, string hoten, float dlt, float dth): 
MSSV(mssv), HoTen(hoten), DLT((dlt > 0)?dlt:0), DTH((dth > 0)?dth:0), NgaySinh(NgayThang()) {}
SinhVien::SinhVien(string mssv, string hoten, float dlt, float dth, int d, int m, int y): 
MSSV(mssv), HoTen(hoten), DLT((dlt > 0)?dlt:0), DTH((dth > 0)?dth:0), NgaySinh(NgayThang(d,m,y)) {}
SinhVien::SinhVien(string mssv, string hoten, float dlt, float dth, NgayThang ngaysinh):
MSSV(mssv), HoTen(hoten), DLT((dlt > 0)?dlt:0), DTH((dth > 0)?dth:0), NgaySinh(ngaysinh) {}
SinhVien::SinhVien(const SinhVien& copy):
MSSV(copy.MSSV), HoTen(copy.HoTen), DLT((copy.DLT > 0)?copy.DLT:0), DTH((copy.DTH > 0)?copy.DTH:0), NgaySinh(copy.NgaySinh) {}
void SinhVien::Xuat() {
    cout << "MSSV: " << MSSV << ", HoTen: " << HoTen << ", NgaySinh: ";
    NgaySinh.Xuat();
    cout << ", DLT: " << DLT << ", DTH: " << DTH << ".\n";
}
int main() {
    SinhVien sv1;
    sv1.Xuat();
    SinhVien sv2("1363001");
    sv2.Xuat();
    SinhVien sv3("1363002", "Nguyen Van A", 7, 8.5);
    sv3.Xuat();
    SinhVien sv4("1363003", "Tran Thi B", 8, 9.5, 12, 3, 1996);
    sv4.Xuat();
    NgayThang n(30,2,1996);
    SinhVien sv5("1363004", "Ngo Van C", 5, 6, n);
    sv5.Xuat();
    SinhVien sv6(sv5);
    sv6.Xuat();
    return 0;
}