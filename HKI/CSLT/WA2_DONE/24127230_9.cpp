#include <iostream>
using namespace std;
int main()
{
    int num_penny, num_nickel, num_dime, num_quarter, num_hdcoin, num_1dcoin, total;
    cout << "How many pennies do you have? ";
    cin >> num_penny;
    cout << "How many nickels do you have? ";
    cin >> num_nickel;
    cout << "How many dimes do you have? ";
    cin >> num_dime;
    cout << "How many quarters do you have? ";
    cin >> num_quarter;
    cout << "How many half-dollar coins do you have? ";
    cin >> num_hdcoin;
    cout << "How many one-dollar coins do you have? ";
    cin >> num_1dcoin;
    total = num_penny + 5 * num_nickel + 10 * num_dime + 25 * num_quarter + 50 * num_hdcoin + 100 * num_1dcoin;
    cout << endl
         << "The value of all your coins is " << total << " cents";
    return 0;
}