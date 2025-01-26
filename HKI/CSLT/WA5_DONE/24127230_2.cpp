#include <iostream>
#include <algorithm>
using namespace std;
struct fraction
{
    int numberator, denominator;
};
fraction getFraction()
{
    int x, y;
    cout << "Enter numberator, denominatior: ";
    cin >> x >> y;
    fraction n{x, y};
    return n;
}
void printFraction(fraction x)
{
    if (x.denominator == 1)
        cout << x.numberator << endl;
    else
        cout << x.numberator << "/" << x.denominator << endl;
}
fraction shorten(fraction x)
{
    int GCD = __gcd(x.numberator, x.denominator);
    x.numberator /= GCD;
    x.denominator /= GCD;
    return x;
}
void SubtractionOrAddition_fraction()
{
    cout << "The subtraction/addition of two fractions" << endl;
    fraction a, b;
    a = getFraction();
    b = getFraction();
    int ask;
    cout << "Enter 1 for subtraction, 2 for addition: ";
    cin >> ask;
    if (ask == 1)
    {
        fraction res{a.numberator * b.denominator - b.numberator * a.denominator, a.denominator * b.denominator};
        res = shorten(res);
        cout << endl
             << "Subtraction: ";
        printFraction(res);
    }
    else if (ask == 2)
    {
        fraction res{a.numberator * b.denominator + b.numberator * a.denominator, a.denominator * b.denominator};
        res = shorten(res);
        cout << endl
             << "Addition: ";
        printFraction(res);
    }
}
void MultiplicationOrDivision_fraction()
{
    cout << "The multiplication/division of two fractions" << endl;
    fraction a, b;
    a = getFraction();
    b = getFraction();
    int ask;
    cout << "Enter 1 for multiplication, 2 for division: ";
    cin >> ask;
    if (ask == 1)
    {
        fraction res{a.numberator * b.numberator, a.denominator * b.denominator};
        res = shorten(res);
        cout << endl
             << "Multiplication: ";
        printFraction(res);
    }
    else if (ask == 2)
    {
        fraction res{a.numberator * b.denominator, a.denominator * b.numberator};
        res = shorten(res);
        cout << endl
             << "Division: ";
        printFraction(res);
    }
}
int main()
{
    SubtractionOrAddition_fraction();
    MultiplicationOrDivision_fraction();
    return 0;
}