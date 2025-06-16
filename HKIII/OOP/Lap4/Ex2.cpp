#define MAXLEN 100
class SoNguyenLon
{
private:
int mangSo[MAXLEN];
int soCS;
static SoNguyenLon snlMax;
public:
SoNguyenLon(void);
SoNguyenLon(const int& cs, const int& scs);
SoNguyenLon(const unsigned int& n);
SoNguyenLon(const SoNguyenLon& snl);
~SoNguyenLon(void);
SoNguyenLon operator+(const SoNguyenLon& snl);
SoNguyenLon operator-(const SoNguyenLon& snl);
bool operator>(const SoNguyenLon& snl);
const SoNguyenLon& operator=(const SoNguyenLon& snl);
friend SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl);
friend SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl);
friend ostream& operator<<(ostream& os, const SoNguyenLon& snl);
static SoNguyenLon SNLMax();
};

{
continue;
}
if (mangSo[i] > snl.mangSo[i])
{
return true;
}
return false;
}
return false;
}
const SoNguyenLon& SoNguyenLon::operator=(const SoNguyenLon& snl)
{
soCS = snl.soCS;
for (int i=0; i<soCS; ++i)
{
mangSo[i] = snl.mangSo[i];
}
return *this;
}
SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon& snl)
{
SoNguyenLon snlKQ;
const SoNguyenLon *snlSCSMax = (soCS > snl.soCS) ? this : &snl;
const SoNguyenLon *snlSCSMin = (soCS < snl.soCS) ? this : &snl;
int soCSMin = (soCS > snl.soCS) ? snl.soCS : soCS;
int nho = 0;
for (int i=0; i<snlSCSMin->soCS; ++i)
{
snlKQ.mangSo[i] = mangSo[i] + snl.mangSo[i] + nho;
nho = snlKQ.mangSo[i] / 10;
snlKQ.mangSo[i] %= 10;
}
for (int i=snlSCSMin->soCS; i<snlSCSMax->soCS; ++i)
{
snlKQ.mangSo[i] = snlSCSMax->mangSo[i] + nho;
nho = snlKQ.mangSo[i] / 10;
snlKQ.mangSo[i] %= 10;
}
snlKQ.soCS = snlSCSMax->soCS;
if (nho > 0)
{
snlKQ.mangSo[snlKQ.soCS++] = 1;
}
if (snlKQ > snlMax)
{
snlMax = snlKQ;
}
return snlKQ;
}
SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon& snl)
{
SoNguyenLon snlKQ;
int nho = 0, i;
if (soCS >= snl.soCS)
{
for (i=0; i<snl.soCS; ++i)
{
snlKQ.mangSo[i] = mangSo[i] - snl.mangSo[i] - nho;
nho = 0;
if (snlKQ.mangSo[i] < 0)
{
snlKQ.mangSo[i] += 10;
nho = 1;
}
}
for (; i<soCS; ++i)
{
snlKQ.mangSo[i] = mangSo[i] - nho;
nho = 0;
if (snlKQ.mangSo[i] < 0)
{
snlKQ.mangSo[i] += 10;
nho = 1;
}
}
snlKQ.soCS = soCS;
while(snlKQ.mangSo[snlKQ.soCS-1] == 0)
{
snlKQ.soCS--;
}
}
return snlKQ;
}
SoNguyenLon operator+(const unsigned int& n, const SoNguyenLon& snl)
{
SoNguyenLon snlTemp(n);
SoNguyenLon snlKQ = snlTemp + snl;
if (snlKQ > SoNguyenLon::snlMax)
{
SoNguyenLon::snlMax = snlKQ;
}
return snlKQ;
}
SoNguyenLon operator-(const unsigned int& n, const SoNguyenLon& snl)
{
SoNguyenLon snlTemp(n);
return snlTemp - snl;
}
ostream& operator<<(ostream& os, const SoNguyenLon& snl)
{
for (int i=snl.soCS-1; i>=0; --i)
{
os << snl.mangSo[i];
}
return os;
}


int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(44667733);
    SoNguyenLon snl3(5, 9);
    SoNguyenLon snl4(7, 30);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 1098765432 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
    SoNguyenLon snl8 = snl2 * snl3;
    cout << snl1 << endl << snl2 << endl << snl3 << endl;
    cout << snl4 << endl << snl5 << endl << snl6 << endl;
    cout << snl7 << endl << snl8 << endl << endl;
    return 0;
}