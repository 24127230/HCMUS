#include <iostream>
using namespace std;
int main()
{
    for (int y = 0; y <= 6; y++)
    {
        for (int x = 0; x <= 5; x++)
        {
            if (y == 0 && x >= 1 && x <= 4)
                cout << "# ";
            else if (y == 6 && x >= 1 && x <= 3)
                cout << "# ";
            else if (x == 0 && y >= 1 && y <= 5)
                cout << "# ";
            else if (x == 5 && y >= 1 && y <= 4)
                cout << "# ";
            else if (x >= 3 && y - x == 1)
                cout << "# ";
            else
                cout << "  ";
        }
        cout << "\n";
    }
    return 0;
}
