#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
struct student
{
    string fullName;
    string studentID;
    string dob;
    double gpa;
};
void displayList(int stu[], int n)
{

}
int main()
{
    int choice = 1;
    do
    {
        system("cls");

        cout << ((choice == 1)?"->":"  ") << "1. Display the list of students\n";
        cout << ((choice == 2)?"->":"  ") << "2. Add a new student to the list\n";
        cout << ((choice == 3)?"->":"  ") << "3. Remove a student from the list based on their student ID\n";
        cout << ((choice == 4)?"->":"  ") << "4. Update student information (full name, date of birth, GPA)\n";
        cout << ((choice == 5)?"->":"  ") << "5. Find the student with the highest GPA\n";
        cout << ((choice == 0)?"->":"  ") << "0. End\n";
        char key = getch();
        switch(key)
        {
        case 72://up button
            choice--;
            if(choice < 0)choice = 5;
            break;
        case 80://down button
            choice++;
            if(choice > 5)choice = 0;
            break;
        case 13://enter button
            switch(choice)
            {
            case 1:
                cout << "do 1\n";
                break;
            case 2:
                cout << "do 2\n";
                break;
            case 3:
                cout << "do 3\n";
                break;
            case 4:
                cout << "do 4\n";
                break;
            case 5:
                cout << "do 5\n";
                break;
            case 0:
                cout << "End\n";
                return 0;
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
            system("pause");
            break;
        }
    }while(1);

    return 0;
}
