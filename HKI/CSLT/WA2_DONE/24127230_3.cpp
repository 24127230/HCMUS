#include <iostream>
using namespace std;
int main()
{
    float Distance_kilometer, Distance_mile;
    cout << "Input the distance in kilometers: ";
    cin >> Distance_kilometer;
    Distance_mile = Distance_kilometer / 1.609344;
    cout << "The distance in mile: " << Distance_mile;
    return 0;
}