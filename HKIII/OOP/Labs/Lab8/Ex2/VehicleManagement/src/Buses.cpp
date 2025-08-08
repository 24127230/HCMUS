#include <iostream>
#include "../include/Buses.h"

using namespace std;

Buses::Buses(string license, string facturer, int year, double w, int route)
    : Vehicle(license, facturer, year, w), numberOfRoutes(route) {
    Vehicle::totalFee += calculateFee();
}
Buses::~Buses() {}
void Buses::displayInfo() {
    cout << "       ====Bus====\n";
    Vehicle::displayInfo();
    cout << "Number of routes: " << numberOfRoutes << endl;
    cout << "circulation fees: " << calculateFee() << endl;
    cout << "       ===========\n";
}
double Buses::calculateFee() {
    double fee = 2000000 + (300000 * numberOfRoutes);
    return fee;
}
void Buses::inputInfo() {
    cout << "====Buses input====\n";
    Vehicle::inputInfo();
    cout << "Number of routes: ";
    cin >> numberOfRoutes;
    cin.ignore();
}