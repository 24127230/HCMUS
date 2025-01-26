#include <iostream>
using namespace std;
int main()
{
    int temp;
    cin >> temp;
    if (temp < 0)
        cout << "Freezing weathe";
    else if (temp < 10)
        cout << "Very Cold weather";
    else if (temp < 20)
        cout << "Cold weather";
    else if (temp < 30)
        cout << "Normal in Temp";
    else if (temp < 40)
        cout << "Its Hot";
    else
        cout << "Its Very Hot";
    return 0;
}