#include <iostream>
#include <cmath>
using namespace std;

int res[11];

bool IsSave(int &row, int &col)
{
    for (int i = 1; i < row; i++)
    {
        if (res[i] == col || abs(res[i] - col) == abs(i - row))
            return 0;
    }
    return 1;
}

void PrintRes(int &n) {
    cout << "[";
    for(int row = 1; row <= n; row++){
        cout << res[row] << ((row == n) ? "" : ", ");
    }
    cout << "]\n";
}

void NQueen(int row, int &n) {
    if (row == n + 1)
    {
        PrintRes(n);
        return;
    }
    for (int col = 1; col <= n; col++){
        if(IsSave(row, col)) {
            res[row] = col;
            NQueen(row + 1, n);
            res[row] = 0;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    NQueen(1, n);
    return 0;
}