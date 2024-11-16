#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    float x1, x2, y1, y2, Distance;
    cout << "Input x1: ";
    cin >> x1;
    cout << "Input y1: ";
    cin >> y1;
    cout << "Input x2: ";
    cin >> x2;
    cout << "Input y2: ";
    cin >> y2;
    Distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
    cout << "Distance between the two given points: " << Distance;
    return 0;
}