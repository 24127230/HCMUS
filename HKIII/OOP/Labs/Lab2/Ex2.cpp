#include <iostream>
#include <string>

using namespace std;

class SoNguyenLon {
private: 
    string number;
public:
    SoNguyenLon();
    SoNguyenLon(unsigned long long int so);
    SoNguyenLon(string so);
    SoNguyenLon(int so_bi_lap, int so_luong);
    static SoNguyenLon SNLMax();
    SoNguyenLon Add(const SoNguyenLon &socong);
    SoNguyenLon Sub(const SoNguyenLon &sotru);
    void Xuat();
};

//write func here
SoNguyenLon::SoNguyenLon(): number("0") {}
SoNguyenLon::SoNguyenLon(unsigned long long int so) {
    if(so < 0) so = -so;
    number = to_string(so); 
}
SoNguyenLon::SoNguyenLon(string so) {
    so.erase(0, so.find_first_not_of('0'));

    if (so.empty()) so = "0";
    if (so.length() > 100000000000000 || so.find_first_not_of("0123456789") != string::npos)
        number = "0";
    else
        number = so;
}
SoNguyenLon::SoNguyenLon(int so_bi_lap, int so_luong) {
    if(so_bi_lap < 0 || so_bi_lap > 9 || so_luong < 0 || so_luong > 10000000000) 
        number = "0";
    else {
        string tmp(so_luong, so_bi_lap + '0');
        number = tmp;
    }
}
void SoNguyenLon::Xuat() {
    cout << number;
}
SoNguyenLon SoNguyenLon::Add(const SoNguyenLon &socong) {
    string sbc = number, sc = socong.number, res = "";
    if (sc.length() > sbc.length()) {
        string tmp = sbc;
        sbc = sc;
        sc = tmp;
    }
    int carry = 0;
    int i = sbc.length()-1, j = sc.length()-1;
    while (i >= 0 || j >= 0 || carry) {
        int ch_sbc = (i >= 0) ? sbc[i--] - '0' : 0;
        int ch_sc = (j >= 0) ? sc[j--] - '0' : 0;
        int sum = ch_sbc + ch_sc + carry;
        res = to_string(sum % 10) + res;
        carry = sum / 10;
    }
    return SoNguyenLon(res);
}
SoNguyenLon SoNguyenLon::Sub(const SoNguyenLon &sotru) {
    string sbt = number, st = sotru.number, res = "";
    int carry = 0;
    if (sbt < st) return SoNguyenLon("0");
    while(st.length() < sbt.length()) st = "0" + st;
    int i = sbt.length()-1;
    while (i >= 0) {
        int ch_sbt = sbt[i] - '0';
        int ch_st = st[i] - '0' + carry;
        if (ch_sbt < ch_st) {
            ch_sbt += 10;
            carry = 1;
        }
        else   
            carry = 0;
        res = to_string(ch_sbt-ch_st) + res;
        i--;
    }
    while (res.length() > 1 && res[0] == '0') res.erase(0, 1);
    return SoNguyenLon(res);
}
SoNguyenLon SoNguyenLon::SNLMax() {
    return SoNguyenLon(9, 20);
}
int main()
{
    SoNguyenLon snl1;
SoNguyenLon snl2(44667733);
SoNguyenLon snl3(5, 9);
SoNguyenLon snl4(7, 30);
SoNguyenLon snl5 = snl3.Sub(snl2);
SoNguyenLon snl6 = SoNguyenLon(1098765432).Sub(snl2);
SoNguyenLon snl7 = (snl4.Sub(snl3)).Add(SoNguyenLon(123456789));
// SoNguyenLon snl8 = snl2 * snl3;
    snl1.Xuat(); cout << endl;
    snl2.Xuat(); cout << endl;
    snl3.Xuat(); cout << endl;
    snl4.Xuat(); cout << endl;
    snl5.Xuat(); cout << endl;
    snl6.Xuat(); cout << endl;
    snl7.Xuat(); cout << endl << endl;
    cout << "SoNguyenLon Max:" << endl;
    SoNguyenLon::SNLMax().Xuat();
    return 0;
}