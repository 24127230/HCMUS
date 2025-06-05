#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "The number of petals: ";
    cin >> n;
    switch (n % 6)
    {
    case 1:
        cout << "I love you";
        break;
    case 2:
        cout << "a little";
        break;
    case 3:
        cout << "a lot";
        break;
    case 4:
        cout << "passionately";
        break;
    case 5:
        cout << "madly";
        break;
    case 6:
        cout << "not at all";
        break;
    }
    return 0;
}