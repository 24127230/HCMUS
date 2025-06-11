#include <iostream>
using namespace std;
class ThoiGian {
private:
    int h,m,s;
public:
    void Sua();
    ThoiGian();
    ThoiGian(int _s);
    ThoiGian(int _m, int _s);
    ThoiGian(int _h, int _m, int _s);
    static int hms_to_s(int hh, int mm, int ss); 
    friend ostream &operator<<(ostream& os,const ThoiGian& tg);
    ThoiGian operator+(const ThoiGian& other_tg);
    ThoiGian operator-(const ThoiGian& other_tg);
    ThoiGian operator+(int other_tg);
    ThoiGian operator-(int other_tg);
    friend ThoiGian operator+(int other_tg, const ThoiGian& this_tg);
    friend ThoiGian operator-(int other_tg, const ThoiGian& this_tg);
    bool operator<=(const ThoiGian& other_tg);
    friend bool operator<=(int other_tg, const ThoiGian& this_tg);
};

void ThoiGian::Sua() {
    m += s / 60;
    s %= 60;
    h += m / 60;
    m %= 60;
}
int ThoiGian::hms_to_s(int hh, int mm, int ss) {
    return ss + mm * 60 + hh * 60 * 60;
}
ThoiGian::ThoiGian(): h(0), m(0), s(0) {}
ThoiGian::ThoiGian(int _s): h(0), m(0), s(_s < 0 ? -_s : _s){
    this->Sua();
}
ThoiGian::ThoiGian(int _m, int _s): h(0), m(_m < 0 ? -_m : _m), s(_s < 0 ? -_s : _s) {
    this->Sua();
}
ThoiGian::ThoiGian(int _h, int _m, int _s): h(_h < 0 ? -_h : _h), m(_m < 0 ? -_m : _m), s(_s < 0 ? -_s : _s) {
    this->Sua();
}
ostream &operator<<(ostream& os,const ThoiGian& tg) {
    os << (tg.h < 10 ? "0" : "") << tg.h << ":" << (tg.m < 10 ? "0" : "") <<  tg.m << ":" << (tg.s < 10 ? "0" : "") << tg.s;
}
ThoiGian ThoiGian::operator+(const ThoiGian& other_tg) {
    return hms_to_s(h,m,s) + hms_to_s(other_tg.h,other_tg.m,other_tg.s);
}
ThoiGian ThoiGian::operator-(const ThoiGian& other_tg) {
    return (hms_to_s(h,m,s) - hms_to_s(other_tg.h,other_tg.m,other_tg.s) < 0 ? 0 : hms_to_s(h,m,s) - hms_to_s(other_tg.h,other_tg.m,other_tg.s));
}
ThoiGian ThoiGian::operator+(int other_tg) {
    return hms_to_s(h,m,s) + other_tg;
}
ThoiGian ThoiGian::operator-(int other_tg) {
    return (hms_to_s(h,m,s) - other_tg < 0 ? 0 : hms_to_s(h,m,s) - other_tg);
}
ThoiGian operator+(int other_tg, const ThoiGian& this_tg) {
    return other_tg + ThoiGian::hms_to_s(this_tg.h,this_tg.m,this_tg.s);
}
ThoiGian operator-(int other_tg, const ThoiGian& this_tg) {
    return (other_tg - ThoiGian::hms_to_s(this_tg.h,this_tg.m,this_tg.s) < 0 ? 0 : other_tg - ThoiGian::hms_to_s(this_tg.h,this_tg.m,this_tg.s));
}
bool ThoiGian::operator<=(const ThoiGian& other_tg) {
    return hms_to_s(h,m,s) <= hms_to_s(other_tg.h, other_tg.m, other_tg.s);
}
bool operator<=(int other_tg, const ThoiGian& this_tg) {
    return (other_tg <= ThoiGian::hms_to_s(this_tg.h, this_tg.m, this_tg.s));
}

int main() {
    ThoiGian tg1;                   //00:00:00
    ThoiGian tg2(1212);             //00:20:12
    ThoiGian tg3(125,45);           //02:05:45
    ThoiGian tg4(12,239,-78);       //16:00:18
    ThoiGian tg5 = tg2 + tg3;       //02:25:57
    ThoiGian tg6 = 5000 + tg2;      //01:43:32
    ThoiGian tg7 = tg4 - tg6;       //14:16:46
    ThoiGian tg8 = 12300 - tg4;     //00:00:00
    ThoiGian tg9, tg10;
    if (tg8 <= tg3)
    {
        tg9 = tg1 + tg2 + 36000;    //10:20:12
    }
    if (12345 <= tg5)
    {
        tg10 = tg5 + 12345;         //05:51:42
    }
    cout << tg1 << endl << tg2 << endl << tg3 << endl << tg4 << endl;
    cout << tg5 << endl << tg6 << endl << tg7 << endl << tg8 << endl;
    cout << tg9 << endl << tg10 << endl;
    return 0;
}