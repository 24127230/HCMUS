#include <iostream>
#include <algorithm>
#include <conio.h>
#include <string>
using namespace std;

#define MAX_SIZE 100

struct player
{
    string name;
    int numAssists;
    int numGoals;
};

int main()
{
    int n = 0;
    player p[MAX_SIZE];

    int choice = 1;

    do
    {
        system("cls");

        cout << ((choice == 1) ? "-> " : "   ") << "1. Display the list of players in the club.\n";
        cout << ((choice == 2) ? "-> " : "   ") << "2. Add new players to the club.\n";
        cout << ((choice == 3) ? "-> " : "   ") << "3. Remove a player from the club.\n";
        cout << ((choice == 4) ? "-> " : "   ") << "4. Update player information.\n";
        cout << ((choice == 5) ? "-> " : "   ") << "5. Find the best player of the season.\n";
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
            double score;
            double max = INT_MIN;
            int index;
            string name;
            bool found = false;
            bool update = false;
            switch (choice)
            {
            case 1:
                if (n == 0)
                    cout << "Player not found!\n";
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        cout << "Name                   : " << p[i].name << endl;
                        cout << "Number of assists      : " << p[i].numAssists << endl;
                        cout << "Number of goals scored : " << p[i].numGoals << endl;
                        cout << "-------------------------------------" << endl;
                    }
                }
                break;
            case 2:
                cin.ignore();
                cout << "Enter name                     : ";
                getline(cin, p[n].name);
                cout << "Entter Number of assists       : ";
                cin >> p[n].numAssists;
                cout << "Enter Number of goals scored   : ";
                cin >> p[n].numGoals;
                cin.ignore();

                n++;
                break;
            case 3:
                cout << "Enter name of a player wanted to remove: ";
                getline(cin, name);
                for (int i = 0; i < n; i++)
                {
                    if (p[i].name == name)
                    {
                        for (int j = i; j < n - 1; j++)
                            p[j] = p[j + 1];
                        n--;
                        found = true;
                        break;
                    }
                }
                if (found)
                    cout << "Player removed successfully." << endl;
                else
                    cout << "Player not found!" << endl;

                cin.ignore();
                break;
            case 4:
                cout << "Enter name of a player wanted to update information: ";
                getline(cin, name);
                for (int i = 0; i < n; i++)
                {
                    if (p[i].name == name)
                    {
                        cout << "Enter Number of assists        : ";
                        cin >> p[i].numAssists;
                        cout << "Enter Number of goals scored   : ";
                        cin >> p[i].numGoals;
                        update = true;
                        break;
                    }
                }
                if (!update)
                    cout << "Player not found!" << endl;

                cin.ignore();
                break;
            case 5:
                if (n == 0)
                {
                    cout << "No students to find best player." << endl;
                }
                else
                {
                    for (int i = 0; i < n; i++)
                    {
                        score = 0.4 * p[i].numAssists + 0.6 * p[i].numGoals;
                        if (score > max)
                        {
                            max = score;
                            index = i;
                        }
                    }
                    cout << " The best player of the season is: " << p[index].name;
                }
                break;
            case 0:
                cout << "Thank you!" << endl;
                return 0;
                break;
            }
            system("pause");
            break;
        }
    } while (true);

    return 0;
}