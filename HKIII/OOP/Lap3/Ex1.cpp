#include <iostream>
using namespace std;

class Ngay
{
private:
    int d, m, y;
hi
public:
    Ngay();
    Ngay(int input_day);
    Ngay(int input_day, int input_month, int input_year);
    friend ostream &operator<<(ostream &, const Ngay &);
};
Ngay::Ngay() : d(1), m(1), y(1) {}
// Ngay::Ngay(int input_day);
Ngay::Ngay(int input_day, int input_month, int input_year) {
    int day;
    if (input_day < 0) input_day = -input_day;
    if (input_month < 0) input_month = -input_month;
    if (input_year < 0) input_year = -input_year;

    input_year += input_month/12;
    input_month = input_month%12;

    if ((input_year%4==0 && input_year%100!=0) || input_year%400==0) {  //is lead y
        
    }
}
ostream &operator<<(ostream &os, const Ngay &ng)
{
    os << ng.d << "/" << ng.m << "/" << ng.y << endl;
    return os;
}
int main()
{
    Ngay n1;               // 1/1/1
    Ngay n2(02, 10, 2014); // 2/10/2014
    // Ngay n3(-10, 16, 2000);      // 10/04/2001
    // Ngay n4(1000);               // 27/9/3
    // Ngay n5 = n2 + n3;           // 12/2/4016
    // Ngay n6 = n1 + 5000;         // 10/10/15
    // Ngay n7 = 1234 + n4;         // 14/2/7
    // Ngay n8 = 199 + n6 + n7;     // 2/7/23
    // Ngay n9 = n8 - n6;           // 1/9/7
    // Ngay n10 = 12999 - n9;       // 9/2/26
    // if (n10 > n6)
    // {
    //     n10 n2 - 1000 + n6;
    // }
    cout << n1;
    // cout << n1 << endl << n2 << endl << n3 << endl << n4 << endl;
    // cout << n5 << endl << n6 << endl << n7 << endl << n8 << endl;
    // cout << n9 << endl << n10 << endl;
    return 0;
}
499+19+4+356*1999