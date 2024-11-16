#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float a, b, c;
    cout << "Input a: ";
    cin >> a;
    cout << "Input b: ";
    cin >> b;
    cout << "Input c: ";
    cin >> c;
    float delta = (b * b) - (4 * a * c);
    if (delta > 0) // 2 ng phan biet
    {
        cout << "x1 = " << (-b - sqrt(delta)) / (2 * a) << endl;
        cout << "x2 = " << (-b + sqrt(delta)) / (2 * a);
    }
    else if (delta == 0) // nghiem kep
    {
        cout << "x = " << (-b) / (2 * a);
    }
    else
        cout << "No real root"; // vo nghiem
}