#include <iostream>
using namespace std;
int decimalToBinary(int x)
{
    if (x == 0)
        return 0;
    if (x == 1)
        return 1;
    return x % 2 + 10 * decimalToBinary(x / 2);
}
int main()
{
    int decimal, binary;
    cin >> decimal;
    binary = decimalToBinary(decimal);
    cout << binary;
    return 0;
}
