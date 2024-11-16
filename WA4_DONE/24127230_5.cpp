#include <iostream>
#include <cmath>
const int N = 1e4 + 5;
using namespace std;
bool isPentagonal(int x)
{
    if (int((1 + sqrt(1 + 24 * x)) / 6) == ((1 + sqrt(1 + 24 * x)) / 6))
        return 1;
    return 0;
}

int main()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            if (isPentagonal((3 * (i * i + j * j) - (i + j)) / 2) && isPentagonal((3 * (j * j - i * i) - (j - i)) / 2))
            {
                cout << i << " " << j << endl;
                cout << (3 * (j * j - i * i) - (j - i)) / 2;
                return 1;
            }
        }
    }
    return 0;
}