#include <iostream>
using namespace std;
int main()
{
    cout << "Input the two real numbers: ";
    float a, b;
    cin >> a >> b;
    cout << "Input the character: ";
    char c;
    cin >> c;
    cout << a << " " << c << " " << b << " = ";
    switch (c)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    }
    return 0;
}