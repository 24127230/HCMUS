#include <iostream>
using namespace std;
const int N = 1e4 + 5;
int main()
{
    int a[N];
    a[0] = 1;
    a[1] = 2;
    int index = 2;
    int sum = 2; // sum = a[1]
    do
    {
        a[index] = a[index - 1] + a[index - 2];
        if (a[index] % 2 == 0)
            sum += a[index];
    } while (a[index++] <= 4000000);
    cout << sum;
    return 0;
}