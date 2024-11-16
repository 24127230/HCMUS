#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    const int N = 2e6;
    bool a[N]; // 1 neu khong la snt, 0 neu la snt
    a[1] = 1;  // 1 khong la snt
    for (int i = 2; i <= sqrt(N); i++)
    {
        if (a[i] == 0)                          // neu i la snt
            for (int j = i * i; j <= N; j += i) // liet ke cac boi cua i
                a[j] = 1;                       // boi cua i khong la snt
    }
    for (int i = 2; i <= N; i++)
    {
        if (a[i] == 0)
            cout << i << "\n";
    }
    return 0;
}