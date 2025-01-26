#include <iostream>
using namespace std;
int main()
{
    int n = 4;
    for (int y = 0; y <= (n - 1); y++)
    {
        for (int x = 0; x <= (2 * n - 2); x++)
        {
            if (y - x == -(n - 1) || y + x == (n - 1) || y == (n - 1))
                cout << "* ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
    return 0;
}