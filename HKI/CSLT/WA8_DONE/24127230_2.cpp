#include <iostream>
using namespace std;
void convert_temp(double *p)
{
    *p = (*p * 1.8) + 32;
}
int main()
{
    cout << "Temperature in degree Celsius: ";
    double n;
    cin >> n;
    convert_temp(&n);
    cout << "Temperature in degree Fahrenheit: " << n;
    return 0;
}