#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
struct student
{
    string fullName;
    string studentID;
    string dob;
    double gpa = 0;
};
bool isSameID(string a, string b)
{
    if (a.length() != b.length())
        return 0;
    for (int j = 0; j < a.length(); j++)
    {
        if (a[j] != b[j])
        {
            return 0;
        }
    }
    return 1;
}
void displayList(student s[], int n)
{
    if (n == 0)
        cout << "No student\n";
    else
        for (int i = 0; i < n; i++)
        {
            cout << "Student " << i + 1 << ": \n";
            cout << "Name                       : " << s[i].fullName << endl;
            cout << "Student ID                 : " << s[i].studentID << endl;
            cout << "Date of birth              : " << s[i].dob << endl;
            cout << "Grade Point Average (GPA)  : " << s[i].gpa << endl;
            cout << "-------------------------------" << endl;
        }
}
void add(student s[], int &n)
{
    cout << "Name                       : ";
    getline(cin, s[n].fullName);
    cout << "Student ID                 : ";
    getline(cin, s[n].studentID);
    cout << "Date of birth              : ";
    getline(cin, s[n].dob);
    cout << "Grade Point Average (GPA)  : ";
    cin >> s[n].gpa;
    n++;
    cin.ignore();
}
void removeByID(student s[], int &n)
{
    string ID;
    bool t = 0;
    cout << "Enter student ID: ";
    getline(cin, ID);
    for (int i = 0; i < n; i++)
    {
        if (isSameID(s[i].studentID, ID))
        {
            t = 1;
            for (int j = i; j < n; j++)
            {
                s[i].dob = s[i + 1].dob;
                s[i].fullName = s[i + 1].fullName;
                s[i].studentID = s[i + 1].studentID;
                s[i].gpa = s[i + 1].gpa;
            }
            n--;
            i--;
        }
    }
    if (t)
        cout << "Removed\n";
    else
        cout << "No student ID exited\n";
}
void updateByID(student s[], int &n)
{
    string ID;
    bool t = 0;
    cout << "Enter student ID: ";
    getline(cin, ID);
    for (int i = 0; i < n; i++)
    {
        if (isSameID(s[i].studentID, ID))
        {
            t = 1;
            cin.ignore();
            cout << "Name                       : ";
            getline(cin, s[i].fullName);
            cout << "Date of birth              : ";
            getline(cin, s[i].dob);
            cout << "Grade Point Average (GPA)  : ";
            cin >> s[i].gpa;
        }
    }
    if (t)
        cout << "Updated\n";
    else
        cout << "No student ID exited\n";
    cin.ignore();
}
void greatestGPA(student s[], int &n)
{
    double max = 0;
    for (int i = 0; i < n; i++)
    {
        max = (max < s[i].gpa) ? s[i].gpa : max;
    }
    cout << "Highest GPA: " << max << endl;
    for (int i = 0; i < n; i++)
    {
        if (s[i].gpa == max)
        {
            cout << "Name               : " << s[i].fullName << endl;
            cout << "Student ID         : " << s[i].studentID << endl;
            cout << "Date of birth      : " << s[i].dob << endl;
            cout << "----------------------------" << endl;
        }
    }
}
int main()
{
    int choice = 1;
    student s[100];
    int n = 0;
    do
    {
        system("cls");
        cout << ((choice == 1) ? "->" : "  ") << "1. Display the list of students\n";
        cout << ((choice == 2) ? "->" : "  ") << "2. Add a new student to the list\n";
        cout << ((choice == 3) ? "->" : "  ") << "3. Remove a student from the list based on their student ID\n";
        cout << ((choice == 4) ? "->" : "  ") << "4. Update student information (full name, date of birth, GPA)\n";
        cout << ((choice == 5) ? "->" : "  ") << "5. Find the student with the highest GPA\n";
        cout << ((choice == 0) ? "->" : "  ") << "0. End\n";
        char key = getch();
        switch (key)
        {
        case 72: // up button
            choice--;
            if (choice < 0)
                choice = 5;
            break;
        case 80: // down button
            choice++;
            if (choice > 5)
                choice = 0;
            break;
        case 13: // enter button
            switch (choice)
            {
            case 1:
                displayList(s, n);
                break;
            case 2:
                add(s, n);
                break;
            case 3:
                removeByID(s, n);
                break;
            case 4:
                updateByID(s, n);
                break;
            case 5:
                greatestGPA(s, n);
                break;
            case 0:
                cout << "Thank you!\n";
                return 0;
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            system("pause");
            break;
        }
    } while (1);

    return 0;
}
