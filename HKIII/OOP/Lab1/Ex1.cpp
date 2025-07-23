#include <iostream>
using namespace std;

class Ngay
{
private:
    int dd, mm, yy;

public:
    Ngay();
    Ngay(int d, int m, int y);
    void Xuat();
    void Sua(int &d, int &m, int &y);
};
Ngay::Ngay(): dd(1), mm(1), yy(1) {}
Ngay::Ngay(int d, int m, int y)
{
    Sua(d, m, y);
    this->dd = d;
    this->mm = m;
    this->yy = y;
}
void Ngay::Xuat()
{
    cout << this->dd << '/' << this->mm << '/' << this->yy << '\n';
}
void Ngay::Sua(int &d, int &m, int &y)
{
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
int main()
{
    Ngay n1;
    n1.Xuat();
    Ngay n2(02, 10, 2014);
    n2.Xuat();
    Ngay n3(-10, 16, 2000);
    n3.Xuat();
    return 0;
}