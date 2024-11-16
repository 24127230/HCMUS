#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 100;
    int SumOfSquare = n * (n + 1) * (2 * n + 1) / 6;
    int SquareOfSum = pow(n * (n + 1) / 2, 2);
    cout << abs(SumOfSquare - SquareOfSum);
    return 0;
}