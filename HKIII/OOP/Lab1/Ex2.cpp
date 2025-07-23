#include <iostream>
using namespace std;
class ThoiGian {
private:
    int gio, phut, giay;
public:
    ThoiGian();
    ThoiGian(int s);
    ThoiGian(int m, int s);
    ThoiGian(int h, int m, int s);
    void Xuat();
};
ThoiGian::ThoiGian(): gio(0), phut(0), giay(0) {}
ThoiGian::ThoiGian(int s): gio(0), phut(0), giay(0) {
    if (s < 0) s = 0;
    gio += s / 3600;
    phut += (s % 3600) / 60;
    giay += (s % 3600) % 60;
}
ThoiGian::ThoiGian(int m, int s): gio(0), phut(0), giay(0) {
    if (m < 0) m = 0;
    if (s < 0) s = 0;
    //s
    gio += s / 3600;
    phut += (s % 3600) / 60;
    giay += (s % 3600) % 60;

    //m
    gio += m / 60;
    phut += m % 60;
}
ThoiGian::ThoiGian(int h, int m, int s): gio(0), phut(0), giay(0) {
    if (m < 0) m = 0;
    if (s < 0) s = 0;
    if (h < 0) h = 0;
    //s
    gio += s / 3600;
    phut += (s % 3600) / 60;
    giay += (s % 3600) % 60;

    //m
    gio += m / 60;
    phut += m % 60;

    //h
    gio += h;
}
void ThoiGian::Xuat() {
    cout << ((gio < 10) ? "0" : "") << gio << ':' << ((phut < 10) ? "0" : "") << phut << ':' << ((giay < 10) ? "0" : "") << giay << '\n'; 
}
int main() {
    ThoiGian tg1;
    tg1.Xuat();
    ThoiGian tg2(1212);
    tg2.Xuat();
    ThoiGian tg3(125, 45);
    tg3.Xuat();
    ThoiGian tg4(12, 239, -78);
    tg4.Xuat();
    return 0;
}