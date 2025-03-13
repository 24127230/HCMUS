#include <iostream>
#include <fstream>
#include <time.h>
#include <vector>
#include <string>
#include <conio.h>

using namespace std;

struct employee
{
    string id;
    string name;
    int birthyear;
};

bool isgreater(employee a, employee b) 
{
    if (a.birthyear == b.birthyear)
    {
        return (a.name > b.name);
    }
    return (a.birthyear > b.birthyear);
}
void insertion_sort(vector<employee> &arr, int n)
{
    for (int i = 1; i < n; i++)
    {
        employee key;
        key = arr[i];
        int j = i - 1;
        while (isgreater(arr[j], key) && j >= 0)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void Swap(employee &a, employee &b)
{
    employee tmp = a;
    a = b;
    b = tmp;
}
void selection_sort(vector<employee> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (isgreater(arr[min],arr[j]))
                min = j;
        }
        Swap(arr[i], arr[min]);
    }
}
void interchange_sort(vector<employee> &arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (isgreater(arr[i], arr[j]))
                Swap(arr[i], arr[j]);
        }
    }
}
int main()
{
    ifstream fin("employee.txt");
    if (!fin.is_open())
    {
        cerr << "Can not open file to read!\n";
        return 0;
    }
    string line;
    getline(fin, line);
    vector<employee> a;
    while (getline(fin, line))
    {
        employee x;
        int i = line.find(',');
        x.id = line.substr(0, i);
        line.erase(0, i + 1);
        i = line.find(',');
        x.name = line.substr(0, i);
        line.erase(0, i + 1);
        x.birthyear = stoi(line);
        if (x.birthyear > 9999) {
            x.birthyear %= 100;
            time_t now = time(0);
            int currentyear = 1900 + localtime(&now)->tm_year;
            if (x.birthyear > currentyear % 100) {
                x.birthyear += int(currentyear / 100) * 100 - 100;
            }
            else x.birthyear += int(currentyear / 100) * 100;
        }
        a.push_back(x);
    }
    fin.close();

    ofstream fout ("sortedemponage.txt");
    if (!fout.is_open()) {
        cerr << "Can not open file to write!\n";
        return 0;
    }
    fout << "id, name, birth year\n";

    int choice = 1;
    do {
        system("cls");
        cout << "Choose algorithmn: (use up/dowm arrow to change, enter to choose)\n";
        cout << ((choice == 1) ? "-> " : "   ") << "1. Insertion sort\n";
        cout << ((choice == 2) ? "-> " : "   ") << "2. Selection sort\n";
        cout << ((choice == 3) ? "-> " : "   ") << "3. Interchange sort\n";
        char key = getch();
        switch (key)
        {
            case 72:
                choice = (choice == 1) ? 3 : choice - 1;
                break;
            case 80:
                choice = (choice == 3) ? 1 : choice + 1;
                break;
            case 13:
                switch (choice)
                {
                    case 1:
                        insertion_sort(a, a.size());
                        break;
                    case 2:
                        selection_sort(a, a.size());
                        break;
                    case 3:
                        interchange_sort(a, a.size());
                        break;
                }
                for (int i = 0; i < a.size(); i++){
                    fout << a[i].id << ',' << a[i].name << ',' << a[i].birthyear << ((i != a.size() - 1) ? "\n" : "");
                }
                fout.close();
                cout << "Done! Thank for using <3\n";
                return 0;
                break;
        }
    } while (1);

    return 0;
}