#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    float price1, price2;
    int no1, no2;
    cout << "Unit price - Product 1: ";
    cin >> price1;
    cout << "No. of item - Product 1: ";
    cin >> no1;
    cout << "Unit price - Product 2: ";
    cin >> price2;
    cout << "No. of item - Product 2: ";
    cin >> no2;
    cout << "Average Value = " << fixed << setprecision(6) << (price1 * no1 + price2 * no2) / (no1 + no2);
    return 0;
}