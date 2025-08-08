#pragma once
#include "Vehicle.h"

class Buses : public Vehicle
{
private:
    int numberOfRoutes;
public:
    Buses(std::string license = "none", std::string facturer = "none", int year = 0, double w = 0, int route = 0);
    ~Buses();
    void displayInfo() override;
    double calculateFee() override;
    void inputInfo() override;
};