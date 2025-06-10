#include <iostream>
#include <vector>
using namespace std;

const vector<int> daysofmonth = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

class Ngay
{
private:
    int d, m, y;

public:
    Ngay();
    Ngay(int input_day);
    Ngay(int input_day, int input_month, int input_year);
    static int dmy_to_d(int d, int m, int y);
    void d_to_dmy(int day);
    int getDay();
    int getMonth();
    int getYear();
    friend ostream &operator<<(ostream &, const Ngay &);
    bool operator>(const Ngay &other);
    Ngay operator+(const Ngay &other);
    Ngay operator-(const Ngay &other);
    Ngay operator+(int oday);
    Ngay operator-(int oday);
    friend Ngay operator+(int oday, const Ngay& n);
    friend Ngay operator-(int oday, const Ngay& n);
};
int Ngay::getDay() { return d; }
int Ngay::getMonth() { return m; }
int Ngay::getYear() { return y; }
int Ngay::dmy_to_d(int day, int month, int year)
{
    year += month / 12;
    month = month % 12;
    for (int i = 1; i < month; i++)
    {
        day += daysofmonth[i];
        if (i == 2)
            day += ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 1 : 0;
    }
    day += 365 * (year - 1);                                  // tong so ngay cua cac nam khong tinh ngay nhuan
    day += int((year-1) / 4) - int((year-1) / 100) + int((year-1) / 400); // tong so ngay nhuan
    return day - 1;
}
void Ngay::d_to_dmy(int day)
{
    cout << "d:" << day << " to dmy:";
    y = day / 365;
    while (int(y / 4) - int(y / 100) + int(y / 400) + y * 365 > day)
        y--;

    day -= int(y / 4) - int(y / 100) + int(y / 400) + y * 365;
    m = 1;
    for (; m <= 12; m++)
    {
        int tmp = day - daysofmonth[m] - ((m == 2 && (((y + 1) % 4 == 0 && (y + 1) % 100 != 0) || (y + 1) % 400 == 0)) ? 1 : 0);
        if (tmp >= 1)
            day = tmp;
        else
            break;
    }
    y = y + 1;
    d = day + 1;
    cout << d << ' ' << m << ' ' << y <<endl;
}
Ngay::Ngay() : d(1), m(1), y(1) {}
Ngay::Ngay(int input_day)
{
    this->d_to_dmy(input_day);
}
Ngay::Ngay(int input_day, int input_month, int input_year)
{
    if (input_day < 0)
        input_day = -input_day;
    if (input_month < 0)
        input_month = -input_month;
    if (input_year < 0)
        input_year = -input_year;

    int day = dmy_to_d(input_day, input_month, input_year);
    this->d_to_dmy(day);
}
ostream &operator<<(ostream &os, const Ngay &ng)
{
    os << ng.d << "/" << ng.m << "/" << ng.y;
    return os;
}
bool Ngay::operator>(const Ngay &other)
{
    return dmy_to_d(d, m, y) > dmy_to_d(other.d, other.m, other.y);
}
Ngay Ngay::operator+(const Ngay &other)
{
    int day = dmy_to_d(d, m, y) + dmy_to_d(other.d, other.m, other.y);
    return day;
}
Ngay Ngay::operator-(const Ngay &other)
{
    int day = dmy_to_d(d, m, y) - dmy_to_d(other.d, other.m, other.y);
    if (day < 0)
        day = -day;
    return day;
}
Ngay Ngay::operator+(int oday) 
{
    int day = dmy_to_d(d, m, y) + oday;
    return day;
}
Ngay Ngay::operator-(int oday) 
{
    int day = dmy_to_d(d, m, y) - oday;
    if (day < 0)
        day = -day;
    return day;
}
Ngay operator+(int oday, const Ngay& n)
{
    int day = oday + n.dmy_to_d(n.d, n.m, n.y);
    return day;
}
Ngay operator-(int oday, const Ngay& n)
{
    int day = oday - n.dmy_to_d(n.d, n.m, n.y);
    if (day < 0)
        day = -day;
    return day;
}

int main()
{
    Ngay n1;               // 1/1/1 (0)
    Ngay n2(02, 10, 2014); // 2/10/2014 (735507)
    Ngay n3(10, 4, 2001);  // 10/4/2001 (730584)
    Ngay n4(1000);         // 28/9/3

    cout << n1 + Ngay(4, 1, 1) << endl; // 4/1/1 (3)
    cout << Ngay(4, 1, 1) - 3 << endl;  // 1/1/1 (0)
    cout << Ngay(4, 1, 1) - 4 << endl;  // 2/1/1 (-1) -> (1)
    cout << endl;

    Ngay n5 = n2 + n3;       // 9/1/4015 (1466091)
    Ngay n6 = n1 + 5000;     // 10/9/14 (5000)
    Ngay n7 = 1234 + n4;     // 13/2/7 (2234)
    Ngay n8 = 190 + n6 + n7; // 30/4/21 (7424)
    Ngay n9 = n8 - n6;       // 22/8/7 (2424)
    Ngay n10 = 12000 - n9;   // 22/3/27 (9576)

    if (n10 > n6)
    {
        n10 = n2 - 1000 + n6; // 14/9/2025 (739507)
    }
    cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
    cout << n9 << endl << n10 << endl;
    return 0;
}