#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int *findLongestAscendingSubarray(int *a, int n, int &length);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    f(i, 0, n) cin >> *(a + i);
    int l = 0;
    int *sa = findLongestAscendingSubarray(a, n, l);
    cout << "The longest ascending subarray: ";
    f(i, 0, l) cout << *(sa + i) << " ";
    cout << "\nThe length of the subarray: " << l;
    delete[] a;
    return 0;
}
int *findLongestAscendingSubarray(int *a, int n, int &length)
{
    int cnt = 0;
    int *suba = nullptr;
    f(i, 0, n)
    {
        cnt++;
        if (cnt > length)
        {
            length = cnt;
            suba = a + i - cnt + 1;
        }
        if (i != n - 1 && *(a + i) > *(a + i + 1))
        {
            cnt = 0;
        }
    }
    return suba;
}