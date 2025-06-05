#include <iostream>
using namespace std;
int main()
{
    int n, sum = 0;
    cout << "Please enter a number: ";
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (i % 3 == 0 || i % 5 == 0)
            sum += i;
    }
    cout << "Sum of the number 1 to " << n << " is: " << sum;
    return 0;
}