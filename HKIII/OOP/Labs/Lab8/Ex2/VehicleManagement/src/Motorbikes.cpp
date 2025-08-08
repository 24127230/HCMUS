#include <iostream>
#include "../include/Motorbikes.h"

using namespace std;

Motorbikes::Motorbikes(std::string license, std::string facturer, int year, double w, double ED)
    : Vehicle(license, facturer, year, w), engineDisplacement(ED) {
    Vehicle::totalFee += calculateFee();
}
Motorbikes::~Motorbikes() {}
void Motorbikes::displayInfo() {
    cout << "       ====Motorbike====\n";
    Vehicle::displayInfo();
    cout << "Engine displacement(cc): " << engineDisplacement << endl;
    cout << "circulation fees: " << calculateFee() << endl;
    cout << "       =================\n";
}
double Motorbikes::calculateFee() {
    double fee;
    if (engineDisplacement <= 100) fee = 1000000.0;
    if (engineDisplacement > 100 && engineDisplacement < 175) fee = 2000000.0;
    if (engineDisplacement >= 175) fee = 4000000.0;
    return fee;
}
void Motorbikes::inputInfo() {
    cout << "====Motorbikes input====\n";
    Vehicle::inputInfo();
    cout << "Engine displacement(cc): ";
    cin >> engineDisplacement;
    cin.ignore();
}