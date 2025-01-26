#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const int N = 1000000;
    float sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += pow(-1, i + 1) / (2 * i - 1);
    }
    cout << 4 * sum;
    return 0;
}