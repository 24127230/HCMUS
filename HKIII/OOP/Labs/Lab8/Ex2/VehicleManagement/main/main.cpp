#include <iostream>
#include <vector>
#include <conio.h>
#include <iomanip>
#include  "Vehicle.h"
#include "Motorbikes.h"
#include "PassengerCars.h"
#include "Trucks.h"
#include "Buses.h"

using namespace std;
int main() {
    vector<Vehicle*> list;
    int choice = 1;
    do {
        system("cls");
        cout << "<---VEHICLE MANAGEMENT--->\nChoose type of vehicle to input\n";
        cout << ((choice == 1) ? "-> " : "   ") << "1. Motorbikes\n";
        cout << ((choice == 2) ? "-> " : "   ") << "2. Passenger cars\n";
        cout << ((choice == 3) ? "-> " : "   ") << "3. Trucks\n";
        cout << ((choice == 4) ? "-> " : "   ") << "4. Buses\n";
        cout << ((choice == 5) ? "-> " : "   ") << "Finish input\n";
        char key = getch();
        switch (key) {
            case 72:
                choice--;
                if (choice < 1) choice = 5;
                break;
            case 80:
                choice++;
                if (choice > 5) choice = 1;
                break;
            case 13: {
                string license, facturer;
                int year;
                double we;
                if (choice >= 1 && choice <= 4) {
                    cout << "License plate number: ";
                    getline(cin, license);
                    cout << "Manufacturer: ";
                    getline(cin, facturer);
                    cout << "Year of manufacture: ";
                    cin >> year;
                    cout << "Weight: ";
                    cin >> we;
                    cin.ignore();
                }
                switch (choice)
                {
                    case 1: {
                        double ED;
                        cout << "Engine displacement(cc): ";
                        cin >> ED;
                        cin.ignore();
                        list.push_back(new Motorbikes(license, facturer, year, we, ED));
                        break;
                    }
                    case 2: {
                        int seat;
                        cout << "Number of seats: ";
                        cin >> seat;
                        cin.ignore();
                        list.push_back(new PassengerCars(license, facturer, year, we, seat));
                        break;
                    }
                    case 3: {
                        double LC;
                        cout << "Load capicity(kg): ";
                        cin >> LC;
                        cin.ignore();
                        list.push_back(new Trucks(license, facturer, year, we, LC));
                        break;
                    }
                    case 4:{
                        int route;
                        cout << "Number of routes: ";
                        cin >> route;
                        cin.ignore();
                        list.push_back(new Buses(license, facturer, year, we, route));
                        break;
                    }
                    case 5: {
                        cout << fixed << setprecision(2);
                        cout << "+++++++++++++++++++++++++++\n";
                        cout << "+   VEHICLES INFOMATION   +\n" ;
                        cout << "+++++++++++++++++++++++++++\n" << "I. List:\n";
                        double ma = 0.0;
                        for (Vehicle* it : list) {
                            it->displayInfo();
                            if (it->calculateFee() > ma)
                                ma = it->calculateFee();
                        }
                        cout << "   II. Total circulation fee collected: " << Vehicle::getTotalFee() << endl;
                        cout << "   III. Highest fee vehicle: \n";
                        for (Vehicle* it : list) {
                            if (it->calculateFee() == ma)
                                it->displayInfo();
                        }
                        break;
                    }
                    default: {
                        cout << "Invalid choice\n";
                        break;
                    }
                }
                system("pause");
                break;
            }
        }
    } while (1);
    for (Vehicle* it : list) {
        delete it;
    }
    return 0;
}
