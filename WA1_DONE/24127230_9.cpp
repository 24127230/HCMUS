#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int y = 0; y <= n - 1; y++)
    {
        for (int x = 0; x <= (n * 2) - 2; x++)
        {
            if (x >= y && x <= (2 * n - 2) - y)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
    return 0;
}