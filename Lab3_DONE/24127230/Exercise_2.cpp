#include <iostream>
using namespace std;
void calculateBMI()
{
    float w, h;
    cin >> w >> h;
    cout << w / (h * h);
}
int main()
{
    calculateBMI();
    return 0;
}