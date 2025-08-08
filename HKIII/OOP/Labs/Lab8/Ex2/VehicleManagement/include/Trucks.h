#pragma once
#include "Vehicle.h"

class Trucks : public Vehicle
{
private:
    double loadCapacity;
public:
    Trucks(std::string license = "none", std::string facturer = "none", int year = 0, double w = 0, double LC = 0);
    ~Trucks();
    void displayInfo() override;
    double calculateFee() override;
    void inputInfo() override;
};