#include <iostream>
using namespace std;
int main()
{
    int num_penny, num_nickel, num_dime, num_quarter, num_hdcoin, num_1dcoin, total;
    cout << "How many cents do you have? ";
    cin >> total;
    num_1dcoin = total / 100;
    total %= 100;
    num_hdcoin = total / 50;
    total %= 50;
    num_quarter = total / 25;
    total %= 25;
    num_dime = total / 10;
    total %= 10;
    num_nickel = total / 5;
    total %= 5;
    num_penny = total;
    cout << "You have " << num_1dcoin << " one-dollar coins, " << num_hdcoin << " half-dollar coins, " << num_quarter << " quarters, " << num_dime << " dimes, " << num_nickel << " nickels and " << num_penny << " pennies.";
    return 0;
}