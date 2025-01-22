#include <iostream>
#include <stack>
using namespace std;
void twofirst(int n)
{
    stack<int> num;
    while (n)
    {
        num.push(n % 10);
        n /= 10;
    }
    cout << num.top();
    num.pop();
    cout << num.top();
}
void twolast(int n)
{
    cout << (n / 10) % 10 << n % 10;
}
int main()
{
    int n;
    cin >> n;
    if (n > 99)
    {
        twofirst(n);
        cout << ' ';
        twolast(n);
    }
    return 0;
}