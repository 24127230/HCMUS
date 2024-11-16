#include <iostream>
using namespace std;
void nextMonth(int &day, int &month)
{
    month++;
    day = 1;
}
int main()
{
    int day, month, year;
    cin >> day >> month >> year;
    if (month == 2)
    {
        if (year % 400 == 0 || (year % 4 == 0) && (year % 100 != 0)) // leap year
        {
            if (day == 29) // last day
                nextMonth(day, month);
            else if (day > 29) // over last day
            {
                cout << "Not a valid date";
                return 1; // end program so not run line 79
            }
            else
                day++;
        }
        else // not leap year
        {
            if (day == 28)
                nextMonth(day, month);
            else if (day > 28) // over last day
            {
                cout << "Not a valid date";
                return 1; // end program so not run line 79
            }
            else
                day++;
        }
    }
    else if (month == 12)
    {
        if (day == 31) // last day
        {
            day = 1;
            month = 1;
            year++;
        }
        else if (day > 31) // over last day
        {
            cout << "Not a valid date";
            return 1; // end program so not run line 79
        }
        else
            day++;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10)
    {
        if (day == 31) // last day
            nextMonth(day, month);
        else if (day > 31) // over last day
        {
            cout << "Not a valid date";
            return 1; // end program so not run line 79
        }
        else
            day++;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day == 30) // last day
            nextMonth(day, month);
        else if (day > 30) // over last day
        {
            cout << "Not a valid date";
            return 1; // end program so not run line 79
        }
        else
            day++;
    }
    cout << day << " " << month << " " << year;
    return 0;
}