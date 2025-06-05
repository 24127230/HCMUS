#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

#define MAX_SIZE 100

struct car
{
    string manufacturer;
    string model;
    string color;
    int year;
    double price;
    int quantity;
};

struct sell
{
    string manufacturer;
    double price;
    int quantity;
};

int main()
{
    int n = 0;
    car c[MAX_SIZE];

    int m = 0;
    sell s[MAX_SIZE];

    int choice = 1;

    do
    {
        system("cls");

        cout << ((choice == 1) ? "-> " : "   ") << "1. Display the list of available cars in the dealership.\n";
        cout << ((choice == 2) ? "-> " : "   ") << "2. Add new cars to the list.\n";
        cout << ((choice == 3) ? "-> " : "   ") << "3. Sell an available car\n";
        cout << ((choice == 4) ? "-> " : "   ") << "4. Remove old cars from the list\n";
        cout << ((choice == 5) ? "-> " : "   ") << "5. Save the list of sold cars and summarize sales\n";
        cout << ((choice == 0) ? "-> " : "   ") << "0. Exit\n";

        char key = getch();

        switch (key)
        {
        case 72:
            choice--;
            if (choice < 0)
                choice = 5;
            break;
        case 80:
            choice++;
            if (choice > 5)
                choice = 0;
            break;
        case 13:
            bool found = false;
            int oldi = 0;
            string manu;
            int quantity;
            switch (choice)
            {
            case 1:
                if (n == 0)
                    cout << "No car!\n";
                else
                    for (int i = 0; i < n; i++)
                    {
                        cout << "Manufacturer           : " << c[i].manufacturer << "\n";
                        cout << "Model                  : " << c[i].model << "\n";
                        cout << "Color                  : " << c[i].color << "\n";
                        cout << "Year of manufacturer   : " << c[i].year << "\n";
                        cout << "Price                  : " << c[i].price << "\n";
                        cout << "Quantity               : " << c[i].quantity << "\n";
                        cout << "-----------------------------------------------\n";
                    }
                break;
            case 2:
                cout << "Enter Maufacturer: ";
                getline(cin, c[n].manufacturer);
                cout << "Enter Model: ";
                getline(cin, c[n].model);
                cout << "Enter Color: ";
                getline(cin, c[n].color);
                cout << "Enter Year of manufacturer: ";
                cin >> c[n].year;
                while (c[n].year < 0)
                {
                    cout << "Invalid Year. Enter again: ";
                    cin >> c[n].year;
                }

                cout << "Enter Price: ";
                cin >> c[n].price;
                while (c[n].price < 0)
                {
                    cout << "Invalid price. Enter again: ";
                    cin >> c[n].price;
                }

                cout << "Enter Quantity: ";
                cin >> c[n].quantity;
                while (c[n].quantity < 0)
                {
                    cout << "Invalid Quantity. Enter again: ";
                    cin >> c[n].quantity;
                }

                n++;
                cin.ignore();
                break;
            case 3:
                cout << "Enter Manufacturer wanted to sell: ";
                getline(cin, manu);
                if (n == 0)
                    cout << "Can't sell because car is not available\n";
                else
                {
                    cout << "Enter Quantity wanted to buy: ";
                    cin >> quantity;
                    while (quantity <= 0)
                    {
                        cout << "Invalid Quantity\n";
                        cin >> quantity;
                    }

                    for (int i = 0; i < n; i++)
                    {
                        if (c[i].manufacturer == manu)
                        {
                            found = true;
                            if (c[i].quantity < quantity)
                                cout << "Can't sell because insufficient quantity\n";
                            else
                            {
                                cout << "Sell successfully!\n";
                                s[m].manufacturer = manu;
                                s[m].quantity = quantity;
                                s[m].price = c[i].price;
                            }
                        }
                        if (found)
                            cout << "Can't sell because car is not available\n";
                    }
                }

                if (s[m].quantity != 0)
                    m++;
                cin.ignore();
                break;
            case 4:
                if (n == 0)
                    cout << "There is no car to remove\n";
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        if (c[i].year > c[oldi].year)
                            oldi = i;
                    }
                    for (int i = 0; i < n; i++)
                    {
                        if (i == oldi)
                        {
                            for (int j = i; j < n - 1; j++)
                                c[j] = c[j + 1];
                            n--;
                            break;
                        }
                    }
                }
                break;
            case 5:
                if (m == 0)
                    cout << "None of the cars have been sold yet.\n";
                else
                {
                    double sum = 0;
                    cout << "LIST OF SOLD\n";
                    for (int i = 0; i < m; i++)
                    {
                        cout << "Manufacturer   : " << s[i].manufacturer << "\n";
                        cout << "Price          : " << s[i].price << "\n";
                        cout << "Quantity       : " << s[i].quantity << "\n";
                        sum += s[i].price * s[i].quantity;
                    }
                    cout << "-----------------------------------------------\n";
                    cout << "SUMMARIZE SALES: " << sum;
                }
                break;
            case 0:
                cout << "Thank you!\n";
                return 0;
            }

            system("pause");
            break;
        }
    } while (true);

    return 0;
}