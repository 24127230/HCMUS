#include "../include/Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(string license, string facturer, int year, double w)
    : licensePlateNumber(license), manufacturer(facturer), yearOfManufacture(year), weight(w) {}
Vehicle::~Vehicle() {}
void Vehicle::displayInfo() {
    cout << "License plate number: " << licensePlateNumber << endl;
    cout << "Manufacturer: " << manufacturer << endl;
    cout << "Year of manufacture: " << yearOfManufacture << endl;
    cout << "Weight: " << weight << endl;
}
double Vehicle::getTotalFee() {
    return totalFee;
}
void Vehicle::inputInfo() {
    cout << "License plate number: ";
    getline(cin, licensePlateNumber);
    cout << "Manufacturer: ";
    getline(cin, manufacturer);
    cout << "Year of manufacture: ";
    cin >> yearOfManufacture;
    cout << "Weight: ";
    cin >> weight;
    cin.ignore();
}
double Vehicle::totalFee = 0.0;