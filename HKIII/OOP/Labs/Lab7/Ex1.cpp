#include <iostream>
#include <cmath>
using namespace std;
void Swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
} 
int GCD(int a, int b)
{
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (b != 0) {
        a %= b;
        Swap(a, b);
    }
    return a;
}

class PS1
{
private:
    int Numerator;
    int Denominator;

public:
    PS1();
    PS1(int nu, int de);
    ~PS1();
    friend istream &operator>>(istream &is, PS1 &obj);
    friend ostream &operator<<(ostream &os, const PS1 &obj);
    void Simpliy();
    PS1 operator+(PS1 other);
};
PS1::PS1() : Numerator(0), Denominator(1) {}
PS1::PS1(int nu, int de)
{
    if (de == 0)
    {
        cerr << "Demoninator cannot be zero.\n";
        de = 1;
    }
    if (de < 0)
    {
        nu = -nu;
        de = -de;
    }
    Numerator = nu;
    Denominator = de;
}
PS1::~PS1() {}
istream &operator>>(istream &is, PS1 &obj)
{
    int nu, de;
    cout << "--Enter fraction--\n";
    cout << "Numerator: ";
    is >> nu;
    do
    {
        cout << ", demoninator: ";
        is >> de;
        if (de == 0)
        {
            cerr << "Demoninator cannot be zero.\n";
        }
    } while (de == 0);
    if (de < 0)
    {
        nu = -nu;
        de = -de;
    }
    obj.Numerator = nu;
    obj.Denominator = de;
    return is;
}
ostream &operator<<(ostream &os, const PS1 &obj)
{
    os << "Fraction: " << obj.Numerator << "/" << obj.Denominator << endl;
    return os;
}
void PS1::Simpliy()
{
    if (Numerator == 0)
    {
        Denominator = 1;
        return;
    }
    int gcd = GCD(Numerator, Denominator);
    Numerator /= gcd;
    Denominator /= gcd;
    if (Denominator < 0)
    {
        Numerator = -Numerator;
        Denominator = -Denominator;
    }
}
PS1 PS1::operator+(PS1 other) {
    PS1 res((Numerator * other.Denominator) + (other.Numerator * Denominator), Denominator * other.Denominator);
    res.Simpliy();
    return res;
}
class PS2 : public PS1{
private:
    int fractionSign; // -1 negative, +1 positive
public:
    void updateSign();
    PS2();
    PS2(int nu, int de);
    ~PS2();
    friend istream &operator>>(istream &is, PS2 &obj);
    friend ostream &operator<<(ostream &os, const PS2 &obj);
    bool operator==(const PS2& other);
    bool operator!=(const PS2& other);
    bool operator>(const PS2& other);
    bool operator>=(const PS2& other);
    bool operator<(const PS2& other);
    bool operator<=(const PS2& other);
    PS2 operator++(int);
    PS2 operator--(int); 
}

void PS2::updateSign() {
    if (Numerator < 0) {
        fractionSign = -fractionSign;
        Numerator = - Numerator;
    }
    if (Denominator < 0) {
        fractionSign = -fractionSign;
        Denominator = - Denominator;
    }
}
PS2::PS2(): PS1(), fractionSign(1) {
    updateSign();
}
PS2::PS2(int nu, int de): PS1(nu, de), fractionSign(1) {
    updateSign();
    Simpliy();
}
~PS2() {}
istream &operator>>(istream &is, PS2 &obj) {
    
    int si, nu, de;
    cout << "--Enter fraction--\n";
    cout << "Fraction sign(-1/1): ";
    is << si;
    cout << "Numerator: ";
    is >> nu;
    do
    {
        cout << ", demoninator: ";
        is >> de;
        if (de == 0)
        {
            cerr << "Demoninator cannot be zero.\n";
        }
    } while (de == 0);
    if (de < 0)
    {
        nu = -nu;
        de = -de;
    }
    obj.Numerator = nu;
    obj.Denominator = de;
    return is;
}
ostream &operator<<(ostream &os, const PS2 &obj) {
{
    os << "Fraction: " << ((obj.fractionSign == -1) ? "-" : "+") << obj.Numerator << "/" << obj.Denominator << endl;
    return os;
}
}
bool operator==(const PS2& other);
bool operator!=(const PS2& other);
bool operator>(const PS2& other);
bool operator>=(const PS2& other);
bool operator<(const PS2& other);
bool operator<=(const PS2& other);
PS2 operator++(int);
PS2 operator--(int); 

int main()
{
    {   // a)
        PS1 a, b;
        cin >> a;
        cin >> b;
        PS1 c = a + b;
        cout << c;
    }
    {   // b)

    }
    return 0;
}