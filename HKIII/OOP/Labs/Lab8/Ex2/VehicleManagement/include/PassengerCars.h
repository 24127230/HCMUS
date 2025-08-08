#pragma once
#include "Vehicle.h"

class PassengerCars : public Vehicle
{
private:
    int numOfSeats;
public:
    PassengerCars(std::string license = "none", std::string facturer = "none", int year = 0, double w = 0, int seat = 0);
    ~PassengerCars();
    void displayInfo() override;
    double calculateFee() override;
    void inputInfo() override;
};