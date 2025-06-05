#include <iostream>
using namespace std;

int SumOfDigit(int n)
{
    if(n < 10) return n;
    return n % 10 + SumOfDigit(n / 10);
}

int main()
{
    int n;
    cin >> n;
    cout << SumOfDigit(n);
    return 0;
}