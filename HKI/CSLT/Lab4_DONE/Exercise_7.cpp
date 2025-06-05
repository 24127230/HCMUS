#include <iostream>
using namespace std;
const int N = 1e5 + 5;
#define f(a, b, c) for (int a = b; a < c; a++)
int main()
{
    int n;
    int a[N];
    cin >> n;
    f(i, 0, n) cin >> a[i];
    int start = 0, end = 0, res_s, res_e, maxlenght = 0;
    f(i, 1, n)
    {
        if (a[i - 1] > a[i])
        {
            end = i - 1;
            if (end - start + 1 > maxlenght)
            {
                maxlenght = end - start + 1;
                res_s = start;
                res_e = end;
            }
            start = i;
        }
        if (i == n - 1)
        {
            end = i;
            if (end - start + 1 > maxlenght)
            {
                res_s = start;
                res_e = end;
            }
        }
    }
    f(i, res_s, res_e + 1) cout << a[i] << " ";
    return 0;
}