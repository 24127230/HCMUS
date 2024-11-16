#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float working_hour, MoneyperHour, Salary;
    cout << "Input the working hours of a month: ";
    cin >> working_hour;
    cout << "Salary amount/hour: ";
    cin >> MoneyperHour;
    Salary = working_hour * MoneyperHour;
    cout << "salary = " << Salary;
    return 0;
}