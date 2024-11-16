#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int distance_km;
    float fuel_lt, avg_consumption;
    cout << "Input total distance in km: ";
    cin >> distance_km;
    cout << "Input total fuel spent in liters: ";
    cin >> fuel_lt;
    avg_consumption = distance_km / fuel_lt;
    cout << "Average consumption (km/lt): " << fixed << setprecision(2) << avg_consumption;
    return 0;
}