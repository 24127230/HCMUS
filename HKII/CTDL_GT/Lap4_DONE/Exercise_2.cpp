#include <iostream>
#include <vector>
using namespace std;
void Swap(int &a, int &b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] % 2 != 0)
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] % 2 != 0 && a[i] < a[j])
                    Swap(a[i], a[j]);
            }
        else
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] % 2 == 0 && a[i] > a[j])
                    Swap(a[i], a[j]);
            }
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';

    return 0;
}