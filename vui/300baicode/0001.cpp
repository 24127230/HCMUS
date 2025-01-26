#include <iostream>
using namespace std;
void chuvi(int a)
{
    cout << 4 * a;
}
void dientich(int a)
{
    cout << a * a;
}
int main()
{
    int a;
    cin >> a;
    chuvi(a);
    cout << ' ';
    dientich(a);
    return 0;
}