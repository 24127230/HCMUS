#include <iostream>
using namespace std;
int main()
{
    int s1, s2, s3, Decimal_value;
    cout << "Input the first (lowest) bit: ";
    cin >> s1;
    cout << "Input the second bit:";
    cin >> s2;
    cout << "Input the third bit: ";
    cin >> s3;
    Decimal_value = s1 * 1 + s2 * 2 + s3 * 4; // = s1 * 2^0 + s2 * 2^1 + s3 * 2^2
    cout << "The decimal value of the given binary value is " << Decimal_value;
    return 0;
}