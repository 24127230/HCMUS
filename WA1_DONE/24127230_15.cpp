#include <iostream>
using namespace std;
int main()
{
    cout << "Multiplication Tables 1-12" << "\n";
    for (int i = 1; i <= 12; i++)
    {
        cout << "Table of " << i << "\n";
        for (int j = 1; j <= 10; j++)
        {
            cout << i << " x " << j << " = " << i * j << "\n";
        }
        cout << "\n";
    }
    return 0;
}