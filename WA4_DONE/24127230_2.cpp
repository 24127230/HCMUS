#include <iostream>
using namespace std;
int main()
{
    cout << "Input a number: ";
    int n;
    cin >> n;
    if (n <= 0)
        cout << n << " is not a perfect number.";
    else
    {
        int sum = 1;
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0)
                sum += i;
        }
        if (n == sum)
            cout << n << " is a perfect number.";
        else
            cout << n << " is not a perfect number.";
    }
    return 0;
}
