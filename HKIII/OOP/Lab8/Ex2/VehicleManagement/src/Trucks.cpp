#include <iostream>
#include "../include/Trucks.h"

using namespace std;

Trucks::Trucks(string license, string facturer, int year, double w, double LC)
    : Vehicle(license, facturer, year, w), loadCapacity(LC) {
    Vehicle::totalFee += calculateFee();
}
Trucks::~Trucks() {}
void Trucks::displayInfo() {
    cout << "       ====Truck====\n";
    Vehicle::displayInfo();
    cout << "Load capicity(kg): " << loadCapacity << endl;
    cout << "circulation fees: " << calculateFee() << endl;
    cout << "       =============\n";
}
double Trucks::calculateFee() {
    double fee = (0.05 * loadCapacity) + 1500000;
    return fee;
}
void Trucks::inputInfo() {
    cout << "====Trucks input====\n";
    Vehicle::inputInfo();
    cout << "Load capicity(kg): ";
    cin >> loadCapacity;
    cin.ignore();
}