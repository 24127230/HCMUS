#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Mammal {
protected:
    string* name;
    int* age;
public:
    Mammal(string na = "none", int ag = 0);
    virtual ~Mammal();
    virtual void move();
    virtual void speak();
    virtual void displayInfo();
};
class Dog : public Mammal {
private:
    string* breed;
public:
    Dog(string na = "none", int ag = 0, string bre = "none");
    ~Dog();
    void move() override;
    void speak() override;
    void fetch();
    void displayInfo() override;
};
class Cat : public Mammal {
private:
    string* color;
public:
    Cat(string na = "none", int ag = 0, string colr = "none");
    ~Cat();
    void move() override;
    void speak() override;
    void climb();
    void displayInfo() override;
};
class Horse : public Mammal {
private:
    int* speed;
public:
    Horse(string na = "none", int ag = 0, int spd = 0);
    ~Horse();
    void move() override;
    void speak() override;
    void gallop();
    void displayInfo() override;
};
class GuineaPig : public Mammal {
private:
    int* weight;
public:
    GuineaPig(string na, int ag, int wght);
    ~GuineaPig();
    void move() override;
    void speak() override;
    void hide();
    void displayInfo() override;
};
Mammal::Mammal(string na, int ag) : name(new string(na)), age(new int(ag)) {}
Mammal::~Mammal() {
    if(name) delete name;
    if(age) delete age;
    name = NULL;
    age = NULL;
}
void Mammal::move() {
    cout << "Mammal move\n";
}
void Mammal::speak() {
    cout << "Mammal speak\n";
}
void Mammal::displayInfo() {
    cout << "Information\n";
    cout << "Name: " << *name << endl;
    cout << "Age: " << *age << endl;
}
Dog::Dog(string na, int ag, string bre) : Mammal(na, ag), breed(new string(bre)) {}
Dog::~Dog() {
    if (breed) delete breed;
    breed = NULL;
}
void Dog::move() {
    cout << "Dog move\n";
}
void Dog::speak() {
    cout << "Dog bark\n";
}
void Dog::fetch() {
    cout << "Dog fetch\n";
}
void Dog::displayInfo() {
    Mammal::displayInfo();
    cout << "Breed: " << *breed << endl;
}
Cat::Cat(string na, int ag, string colr): Mammal(na, ag), color(new string(colr)) {}
Cat::~Cat() {
    if (color) delete color;
    color = NULL;
}
void Cat::move() {
    cout << "Cat move\n";
}
void Cat::speak() {
    cout << "Cat meow\n";
}
void Cat::climb() {
    cout << "Cat climb\n";
}
void Cat::displayInfo() {
    Mammal::displayInfo();
    cout << "Color: " << *color << endl;
}
Horse::Horse(string na, int ag, int spd): Mammal(na, ag), speed(new int(spd)) {}
Horse::~Horse() {
    if (speed) delete speed;
    speed = NULL;
}
void Horse::move() {
    cout << "Horse move\n";
}
void Horse::speak() {
    cout << "Horse neighs\n";
}
void Horse::gallop() {
    cout << "Horse gallop\n";
}
void Horse::displayInfo() {
    Mammal::displayInfo();
    cout << "Speed: " << *speed << endl;
}
GuineaPig::GuineaPig(string na, int ag, int wght): Mammal(na, ag), weight(new int(wght)) {}
GuineaPig::~GuineaPig() {
    if (weight) delete weight;
    weight = NULL;
}
void GuineaPig::move() {
    cout << "Guinea pig move\n";
}
void GuineaPig::speak() {
    cout << "Guinea pig squeaks\n";
}
void GuineaPig::hide() {
    cout << "Guinea pig hide\n";
}
void GuineaPig::displayInfo() {
    Mammal::displayInfo();
    cout << "Weight: " << *weight << endl;
}

int main() {
    vector <Mammal*> list;
    list.push_back(new Dog("A", 4, "Chihuahua"));
    list.push_back(new Cat("B", 4, "Grey"));
    list.push_back(new Horse("C", 4, 10));
    list.push_back(new GuineaPig("D", 4, 8));
    for (Mammal* it : list) {
        it->displayInfo();
        it->move();
        it->speak();
    }
    for (Mammal* it : list) {
        delete it;
    }
    return 0;
}