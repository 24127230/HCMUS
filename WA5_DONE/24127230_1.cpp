#include <iostream>
#include <cmath>
using namespace std;
struct complexNum
{
    int real, img;
};
complexNum getComplex()
{
    complexNum a;
    cout << "*Real, imaginary part of number: ";
    cin >> a.real >> a.img;
    return a;
}
void printComplex(complexNum x)
{
    cout << x.real;
    if (x.img >= 0)
        cout << " + ";
    else
        cout << " - ";
    cout << abs(x.img) << "i" << endl;
}
void Calc_sum()
{
    cout << "Calculate sum of two complex number: " << endl;
    complexNum a, b;
    cout << "Enter first number: " << endl;
    a = getComplex();
    cout << "Enter second number: " << endl;
    b = getComplex();
    complexNum sum{a.real + b.real, a.img + b.img};
    cout << "Sum = ";
    printComplex(sum);
}
void Calc_multi()
{
    cout << "Calculate multiplication of two complex number: " << endl;
    complexNum a, b;
    cout << "Enter first number: " << endl;
    a = getComplex();
    cout << "Enter second number: " << endl;
    b = getComplex();
    complexNum multi{a.real * b.real - a.img * b.img, a.real * b.img + b.real * a.img};
    cout << "Multiplication = ";
    printComplex(multi);
}
void conjugate_absolute_argument()
{
    cout << "Calculate complex conjugate, absolute value and argument of a complex number: " << endl;
    complexNum a;
    cout << "Enter first number: " << endl;
    a = getComplex();
    complexNum conjugate_a = {a.real, -a.img};
    cout << "Complex conjugate of number: ";
    printComplex(conjugate_a);
    float absolute_a = sqrt(a.real * a.real + a.img * a.img);
    cout << "Absolute value of number: " << absolute_a << endl;
    complexNum argument_a = {-a.real, -a.img};
    cout << "Argument of number: ";
    printComplex(argument_a);
}
int main()
{
    Calc_sum();
    Calc_multi();
    conjugate_absolute_argument();
    return 0;
}