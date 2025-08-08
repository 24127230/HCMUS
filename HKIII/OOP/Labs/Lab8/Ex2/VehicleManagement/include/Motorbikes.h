#pragma once
#include "Vehicle.h"

class Motorbikes : public Vehicle
{
private:
    double engineDisplacement;
public:
    Motorbikes(std::string license = "none", std::string facturer = "none", int year = 0, double w = 0, double ED = 0);
    ~Motorbikes();
    void displayInfo() override;
    double calculateFee() override;
    void inputInfo() override;
};