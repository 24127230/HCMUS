#include <iostream>
#include <string>
using namespace std;
string num1(char x)
{
    switch (x)
    {
    case '1':
        return "one";
    case '2':
        return "two";
    case '3':
        return "three";
    case '4':
        return "four";
    case '5':
        return "five";
    case '6':
        return "six";
    case '7':
        return "seven";
    case '8':
        return "eight";
    case '9':
        return "nine";
    }
    return "error";
}
string num1_upper(char x)
{
    switch (x)
    {
    case '1':
        return "One";
    case '2':
        return "Two";
    case '3':
        return "Three";
    case '4':
        return "Four";
    case '5':
        return "Five";
    case '6':
        return "Six";
    case '7':
        return "Seven";
    case '8':
        return "Eight";
    case '9':
        return "Nine";
    }
    return "error";
}
string num2(char x)
{
    switch (x)
    {
    case '2':
        return "twen";
    case '3':
        return "thir";
    case '4':
        return "four";
    case '5':
        return "fif";
    case '6':
        return "six";
    case '7':
        return "seven";
    case '8':
        return "eight";
    case '9':
        return "nine";
    }
    return "error";
}
string num2_upper(char x)
{
    switch (x)
    {
    case '2':
        return "Twen";
    case '3':
        return "Thir";
    case '4':
        return "Four";
    case '5':
        return "Fif";
    case '6':
        return "Six";
    case '7':
        return "Seven";
    case '8':
        return "Eight";
    case '9':
        return "Nine";
    }
    return "error";
}
int main()
{
    cout << "Input the three-digit number: ";
    string a;
    cin >> a;
    if (a[0] == '0' && a[1] == '0' && a[2] == '0')
        cout << "zero";
    else if (a[0] != '0') // co hang tram
    {
        cout << num1_upper(a[0]) << " hundred";
        if (a[1] != '0' || a[2] != '0')
        {
            cout << " and ";
            if (a[1] == '1')
            {
                if (a[2] == '1')
                    cout << "eleven";
                else if (a[2] == '2')
                    cout << "twelve";
                else if (a[2] == '0')
                    cout << "ten";
                else
                    cout << num2(a[2]) << "teen";
            }
            else if (a[1] == '0')
                cout << num1(a[2]); // khong check a[2] = 0 vi line 58
            else                    // >= 20
            {
                cout << num2(a[1]) << "ty";
                if (a[2] != '0')
                    cout << "-" << num1(a[2]);
            }
        }
    }
    else if (a[0] == '0') // khong co hang tram
    {
        if (a[1] != '0' || a[2] != '0')
        {
            if (a[1] == '1')
            {
                if (a[2] == '1')
                    cout << "Eleven";
                else if (a[2] == '2')
                    cout << "Twelve";
                else if (a[2] == '0')
                    cout << "Ten";
                else
                    cout << num2_upper(a[2]) << "teen";
            }
            else if (a[1] == '0')
                cout << num1_upper(a[2]); // khong check a[2] = 0 vi line 58
            else                          // >= 20
            {
                cout << num2_upper(a[1]) << "ty";
                if (a[2] != '0')
                    cout << "-" << num1(a[2]);
            }
        }
    }
    cout << ".";
    return 0;
}