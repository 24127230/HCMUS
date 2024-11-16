#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cout << "Input the two numbers: ";
    cin >> m >> n;
    int product = 0;
    for (int i = 0; i < m; i++)
        product += n;
    cout << "The product is " << product;
    return 0;
}