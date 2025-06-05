#include <iostream>
using namespace std;
#define f(a, b, c) for (int a = b; a < c; a++)
int *findLargestTotalSubarray(int *a, int n, int &total, int &length);
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    f(i, 0, n) cin >> *(a + i);
    int t = INT_MIN, l = 0;
    int *suba = findLargestTotalSubarray(a, n, t, l);
    cout << "The subarray with the largest total value: ";
    f(i, 0, l) cout << *(suba + i) << " ";
    cout << "\nThe total value: " << t;
    cout << "\nThe length of the subarray: " << l;
    delete[] a;
    return 0;
}
int *findLargestTotalSubarray(int *a, int n, int &total, int &length)
{
    int *sa = nullptr;
    int cnt = 0;
    int current_total = 0;
    f(i, 0, n)
    {
        current_total += *(a + i);
        cnt++;
        if (current_total > total)
        {
            total = current_total;
            sa = a + i - cnt + 1;
            length = cnt;
        }
        if (current_total < 0)
        {
            cnt = 0;
            current_total = 0;
        }
    }
    return sa;
}