#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b, c;
    cout << "Input the first value: ";
    cin >> a;
    cout << "Input the second value: ";
    cin >> b;
    cout << "Input the third value: ";
    cin >> c;
    if (b == max(a, max(b, c)))
        swap(a, b);
    else if (c == max(a, max(b, c)))
        swap(a, c);
    if (c == max(b, c))
        swap(c, b);
    cout << "Forward order: " << a << " " << b << " " << c << endl;
    cout << "Backward order: " << c << " " << b << " " << a;
    return 0;
}