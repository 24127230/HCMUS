#include <iostream>
#include <vector>
using namespace std;

class Circuit {
protected: 
    double r;
public:
    virtual double calculateResistance() = 0;
    virtual Circuit* clone() = 0;
};
class SingleCircuit {
private:
    double resistance;
public: 
    double calculateResistance() override {
        r = resistance;
        return resistance;
    }
    Circuit* clone() override {
        return new SingleCircuit(*this);
    }
};
class CompositeCircuit : public Circuit{
protected:
    vector<Circuit*> subCircuits;
public:
    void add(Circuit* c) {
        subCircuits.push_back(clone(c)); 
    }
};
class SeriesCircuit : public CompositeCircuit
{
private:
public:
    double calculateResistance() override {
        double res;
        for (*Circuit it : subCircuits) { 
            res += it->calculateResistance();
        }
        r = res;
        return res;
    }
    Circuit* clone() override {
        SeriesCircuit newSeriesCircuit = new SeriesCircuit();
        for (*Circuit it : subCircuits) {
            newSeriesCircuit.subCircuits.push_back(clone(it));
        }
    }
};;
class ParrallelCircuit : public CompositeCircuit
{
private:
public:
    double calculateResistance() override {
        double sum, product, res;
        for (*Circuit it : subCircuits) { 
            sum += it->calculateResistance();
            product *= it->calculateResistnace();
        }
        res = product / sum;
        r = res;
        return res;
    }
    Circuit* clone() override {
        SeriesCircuit newSeriesCircuit = new SeriesCircuit();
        for (*Circuit it : subCircuits) {
            newSeriesCircuit.subCircuits.push_back(clone(it));
        }
    }
};

