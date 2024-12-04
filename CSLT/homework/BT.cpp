#include <iostream>
using namespace std;
int n = 2;
int h[] = {1, 2, 3};
int a[2] = {0};
bool check[10] = {0};
void printres()
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void BT(int index)
{
    for (int i = 1; i <= 3; i++)
    {
        if (check[i] != 0)
            continue;
        a[index] = i;
        check[i] = 1;
        if (index == n - 1)
            printres();
        else
            BT(index + 1);
        check[i] = 0;
    }
}
int main()
{
    BT(0);
    return 0;
}