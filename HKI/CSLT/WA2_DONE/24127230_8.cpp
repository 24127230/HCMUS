#include <iostream>
using namespace std;
int main()
{
    float val1, val2, sum, difference, product, division;
    cout << "Input the first number: ";
    cin >> val1;
    cout << "Input the second number: ";
    cin >> val2;
    sum = val1 + val2;
    difference = val1 - val2;
    product = val1 * val2;
    division = val1 / val2;
    cout << "The sum of two numbers is " << sum << endl;
    cout << "The difference between two numbers is " << difference << endl;
    cout << "The product of two numbers is " << product << endl;
    cout << "The division of two numbers is " << division;
    return 0;
}