#include <iostream>
#include <string>

class PlaneGeometry {
protected:
    string name;

public:
    PlaneGeometry(const string& shapeName) : name(shapeName) {
        cout << "PlaneGeometry constructor called for: " << name << std::endl;
    }
    virtual ~PlaneGeometry() {
        cout << "PlaneGeometry destructor called for: " << name << std::endl;
    }
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
    void displayInfo() const {
        cout << "Shape: " << name << std::endl;
    }
};
class Triangle : public PlaneGeometry {
private:
    double base; 
    double height;
    double side1, side2, side3;

public:
    Triangle(double b, double h, double s1, double s2, double s3)
        : PlaneGeometry("Triangle"), base(b), height(h), side1(s1), side2(s2), side3(s3) {
        cout << "Triangle constructor called." << std::endl;
    }
    ~Triangle() override {
        cout << "Triangle destructor called." << std::endl;
    }
    double calculateArea() const override {
        return 0.5 * base * height;
    }
    double calculatePerimeter() const override {
        return side1 + side2 + side3;
    }
};
class Rectangle : public PlaneGeometry {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : PlaneGeometry("Rectangle"), length(l), width(w) {
        cout << "Rectangle constructor called." << std::endl;
    }

    ~Rectangle() override {
        cout << "Rectangle destructor called." << std::endl;
    }
    double calculateArea() const override {
        return length * width;
    }
    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};
class Square : public Rectangle {
private:
    double side; 

public:
    Square(double s) : Rectangle(s, s), side(s) { 
        this->name = "Square"; 
        cout << "Square constructor called." << std::endl;
    }

    ~Square() override {
        cout << "Square destructor called." << std::endl;
    }
    double calculateArea() const override {
        return side * side;
    }
};

