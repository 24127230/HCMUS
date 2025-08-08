#pragma once
#include <string>
class Vehicle
{
protected:
    std::string licensePlateNumber;
    std::string manufacturer;
    int yearOfManufacture;
    double weight;  
    static double totalFee;
public:
    Vehicle(std::string license = "none", std::string facturer = "none", int year = 0, double w = 0);
    virtual ~Vehicle();
    virtual void displayInfo();
    virtual double calculateFee() = 0;
    static double getTotalFee();
    virtual void inputInfo();
};
