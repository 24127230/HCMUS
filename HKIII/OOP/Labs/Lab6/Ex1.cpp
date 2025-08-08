#include <iostream>
#include <string>
using namespace std;
class Car
{
private:
    string *LicensePlate;
    string *Brand;
    int *Mileage;
    static int CountCreate;

public:
    Car();
    Car(string license, string brand, int mile);
    Car(const Car &other);
    ~Car();
    static int getcnt() {
        return CountCreate;
    }
    // string getLP();
    // string getBrand();
    // int getMileAge();
    void UpdateMileage(int amount);
    bool IsLongDistance();
    bool operator>(const Car &other);
    bool operator>=(const Car &other);
    bool operator<(const Car &other);
    bool operator<=(const Car &other);
    bool operator==(const Car &other);
    bool operator!=(const Car &other);
    friend istream& operator>>(istream& is,Car& obj);
    friend ostream& operator<<(ostream& os,const Car& obj);
};

Car::Car() : LicensePlate(NULL), Brand(NULL), Mileage(NULL) {
    CountCreate++;
}
Car::Car(string license, string brand, int mile) : LicensePlate(new string), Brand(new string), Mileage(new int)
{
    // LicensePlate = new string;
    // Brand = new string;
    // Mileage = new int;
    *LicensePlate = license;
    *Brand = brand;
    *Mileage = mile;
    CountCreate++;
}
Car::Car(const Car &other) : LicensePlate(new string), Brand(new string), Mileage(new int)
{
    *LicensePlate = *other.LicensePlate;
    *Brand = *other.Brand;
    *Mileage = *other.Mileage;
    CountCreate++;
}
Car::~Car()
{
    if (LicensePlate)
        delete LicensePlate;
    if (Brand)
        delete Brand;
    if (Mileage)
        delete Mileage;
}
// string Car::getLP() {
//     if (LicensePlate) return *LicensePlate;
// }
// string Car::getBrand() {
//     if (Brand) return *Brand;
// }
// int Car::getMileAge() {
//     if (Mileage) return *Mileage;
// }
void Car::UpdateMileage(int amount)
{
    if (!Mileage)
        Mileage = new int(0);
    *Mileage += amount;
}
bool Car::IsLongDistance()
{
    if(Mileage) 
        if(*Mileage > 100000) return true;
    return false;
}
bool Car::operator>(const Car& other) {
    if(Mileage && other.Mileage) return *Mileage > *other.Mileage;
    return 0;
}
bool Car::operator>=(const Car& other)  {
    if(Mileage && other.Mileage) return *Mileage >= *other.Mileage;
    return 0;
}
bool Car::operator<(const Car& other) {
    if(Mileage && other.Mileage) return *Mileage < *other.Mileage;
    return 0;
}
bool Car::operator<=(const Car& other) {
    if(Mileage && other.Mileage) return *Mileage <= *other.Mileage;
    return 0;
}
bool Car::operator==(const Car& other) {
    if(Mileage && other.Mileage) return *Mileage == *other.Mileage;
    return 0;
}
bool Car::operator!=(const Car& other) {
    if(Mileage && other.Mileage) return *Mileage != *other.Mileage;
    return 0;
}
istream& operator>>(istream& is, Car& obj) {
    if(!obj.LicensePlate) obj.LicensePlate = new string;
    if(!obj.Brand) obj.Brand = new string;
    if(!obj.Mileage) obj.Mileage = new int;
    cout << "Enter information:\n";
    cout << "License plate: ";
    cin >> *obj.LicensePlate;
    cout << "Brand: ";
    cin >> *obj.Brand;
    cout << "Mileage(kilometers): ";
    cin >> *obj.Mileage;
    
    return is;
}
ostream& operator<<(ostream& os,const Car& obj) {
    cout << "License plate: " << *obj.LicensePlate << endl;
    cout << "Brand: " << *obj.Brand << endl;
    cout << "Mileage(kilometers): " << *obj.Mileage << endl;
    return os;
}
int Car::CountCreate = 0;
int main() {
    Car a;
    cin >> a;
    Car b("abc123", "vincon", 10000);
    b.UpdateMileage(5000);
    cout << "b is long distance: " << (b.IsLongDistance()? "true" : "false\n") ;
    cout << "Number of car create: " << Car::getcnt();
    return 0;
}