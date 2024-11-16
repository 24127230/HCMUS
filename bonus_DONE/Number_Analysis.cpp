#include <iostream>
#include <cmath>
using namespace std;

void numberAnalysis(int n);
int sumDigit(int a)
{
    int sum = 0;
    while (a > 0)
    {
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    numberAnalysis(n);
    return 0;
}
void numberAnalysis(int n)
{
    int valuemin = 1000000, pairmin;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (valuemin > (sumDigit(i) + sumDigit(n / i)))
            {
                valuemin = sumDigit(i) + sumDigit(n / i);
                pairmin = i;
            }
        }
    }
    cout << pairmin << " " << n / pairmin;
}
