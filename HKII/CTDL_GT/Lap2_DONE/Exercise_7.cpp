#include <iostream>
#include <vector>
using namespace std;

int res[10];

void PrintRes(int &n) {
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << ' ';
    }
    cout << '\n';
}

void GeneratePermutation(int index, int &n, pair<int, bool>* a) {
    if (index == n) {
        PrintRes(n);
        return;
    }

    for (int i = 0; i < n; i++)
    { 
        if (a[i].second == 0) {
            res[index] = a[i].first;
            a[i].second = 1;
            GeneratePermutation(index + 1, n, a);
            a[i].second = 0;
        }
    }
}

int main()
{
    int n;
    pair<int, bool> a[10];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = 0;
    }
    
    GeneratePermutation(0, n, a);

    return 0;
}

