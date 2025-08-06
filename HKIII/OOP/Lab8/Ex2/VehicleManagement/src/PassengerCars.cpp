#include <iostream>
#include "../include/PassengerCars.h"

using namespace std;

PassengerCars::PassengerCars(string license, string facturer, int year, double w, int seat)
    : Vehicle(license, facturer, year, w), numOfSeats(seat) {
    Vehicle::totalFee += calculateFee();
}
PassengerCars::~PassengerCars() {}
void PassengerCars::displayInfo() {
    cout << "       ====Passenger car====\n";
    Vehicle::displayInfo();
    cout << "Number of seats: " << numOfSeats << endl;
    cout << "circulation fees: " << calculateFee() << endl;
    cout << "       =====================\n";
}
double PassengerCars::calculateFee() {
    double fee = (500000 * numOfSeats) + (0.01 * weight);
    return fee;
}
void PassengerCars::inputInfo() {
    cout << "====PassengerCars input====\n";
    Vehicle::inputInfo();
    cout << "Number of seats: ";
    cin >> numOfSeats;
    cin.ignore();
}