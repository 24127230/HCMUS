#include <iostream>
using namespace std;
int main()
{
    float Temperature_Celsius, Temperature_Fahrenheit;
    cout << "Input the temperature in Celsius scale: ";
    cin >> Temperature_Celsius;
    Temperature_Fahrenheit = Temperature_Celsius * 1.8 + 32;
    cout << "The temperature in Fahrenheit scale: " << Temperature_Fahrenheit;
    return 0;
}