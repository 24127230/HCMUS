#include <iostream>
using namespace std;

int res[10];

void PrintRes(int &k) {
    cout << "{";
    for(int i = 0; i < k; i++) {
        cout << res[i] << ((i == k - 1) ? "" : ",") ;
    }
    cout << "}\n";
}

void GenerateSubset(int index,int a_index, int &k, int &n, int *a) {
    if (k == index) {
        PrintRes(k);
        return;
    }
    for (int i = a_index; i < n; i++)
    {
        res[index] = a[i];
        GenerateSubset(index + 1, i + 1, k, n, a);
    }
}

int main() {
    int n;
    cin >> n;
    int a[10];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int k = 0; k <= n; k++) {
        GenerateSubset(0, 0, k, n, a);
    }
    return 0;
}