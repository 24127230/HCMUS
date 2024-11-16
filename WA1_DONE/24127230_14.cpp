#include <iostream>
using namespace std;
int sum(int n)
{
    return n * (n + 1) / 2;
}
long long pro(long long n)
{
    if (n == 1)
        return 1;
    else
        return n * pro(n - 1);
}
int main()
{
    long long n;
    char c;
    cout << "Please enter a number: ";
    cin >> n;
    cout << "Enter letter s to computing the sum, p to computing the product of 1 to " << n << " :";
    cin >> c;
    if (c == 's')
        cout << "Sum of the number 1 to " << n << " is: " << sum(n);
    else if (c == 'p')
        cout << "Product of the number 1 to " << n << " is: " << pro(n);
    return 0;
}