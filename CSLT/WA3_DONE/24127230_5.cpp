#include <iostream>
using namespace std;
int main()
{
    cout << "Input a month number: ";
    int month;
    cin >> month;
    switch (month)
    {
    case 2:
        cout << "February";
        break;
    case 1:
        cout << "January";
        break;
    case 3:
        cout << "March";
        break;
    case 5:
        cout << "May";
        break;
    case 7:
        cout << "July";
        break;
    case 8:
        cout << "August";
        break;
    case 10:
        cout << "October";
        break;
    case 12:
        cout << "December";
        break;
    case 4:
        cout << "April";
        break;
    case 6:
        cout << "June";
        break;
    case 9:
        cout << "September";
        break;
    case 11:
        cout << "November";
        break;
    }
    cout << " has ";
    switch (month)
    {
    case 2:
        cout << "28 or 29";
        break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        cout << "31";
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        cout << "30";
        break;
    }
    cout << " days.";
    return 0;
}