#include <iostream>
using namespace std;
int main()
{
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 7; j++)
        {
            if (i == 1 || j == 1 || i == 4 || j == 7)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << '\n';
    }
    return 0;
}