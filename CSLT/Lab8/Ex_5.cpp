#include <iostream>
#include <conio.h>
using namespace std;
struct student
{
    string fullName = "";
    string studentID = "________";
    string dob = "__/__/____";
    double gpa = 0.0;
};
struct Node
{
    student data;
    Node *pNext = NULL;
};
struct LinkedList
{
    Node *pHead = NULL;
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
void displayList(LinkedList &l)
{
    if (l.pHead == NULL)
        cout << "No student!\n";
    else
    {
        Node *p = l.pHead;
        int i = 1;
        while (p != NULL)
        {
            cout << "Student " << i++ << ": \n";
            cout << "Name                     : " << p->data.fullName << endl;
            cout << "Student ID               : " << p->data.studentID << endl;
            cout << "Date of birth            : " << p->data.dob << endl;
            cout << "Grade Point Average (GPA): " << p->data.gpa << endl;
            cout << "-------------------------------" << endl;
            p = p->pNext;
        }
    }
}
void add(LinkedList &l)
{
    Node *newstu = new Node;
    cout << "Name                       : ";
    getline(cin, newstu->data.fullName);
    cout << "Student ID                 : ";
    getline(cin, newstu->data.studentID);
    cout << "Date of birth              : ";
    getline(cin, newstu->data.dob);
    cout << "Grade Point Average (GPA)  : ";
    cin >> newstu->data.gpa;
    cin.ignore();
    if (l.pHead == NULL)
    {
        l.pHead = newstu;
    }
    else
    {
        Node *p = l.pHead;
        while (p->pNext != NULL)
        {
            p = p->pNext;
        }
        p->pNext = newstu;
    }
}
void removeByID(LinkedList &l)
{
    if (l.pHead == NULL)
    {
        cout << "No student!";
    }
    else
    {
        string ID;
        bool t = 0;
        cout << "Enter student ID: ";
        getline(cin, ID);
        while (isSameID(l.pHead->data.studentID, ID))
        {
            t = 1;
            Node *Temp = l.pHead;
            l.pHead = l.pHead->pNext;
            delete Temp;
        }
        Node *prep = l.pHead;
        Node *curp = l.pHead->pNext;
        while (curp != NULL)
        {
            if (isSameID(curp->data.studentID, ID))
            {
                t = 1;
                Node *Temp = curp;
                prep->pNext = curp->pNext;
                delete Temp;
            }
            else
            {
                prep = curp;
                curp = curp->pNext;
            }
        }
        if (t)
            cout << "Removed\n";
        else
            cout << "No student ID exited\n";
    }
}
void updateByID(LinkedList &l)
{
    if (l.pHead == NULL)
        cout << "No student!";
    else
    {
        string ID;
        bool t = 0;
        cout << "Enter student ID: ";
        getline(cin, ID);
        Node *p = l.pHead;
        while (p != NULL)
        {
            
        }
    }
}
void greatestGPA(student s[], int &n);
int main()
{
    int choice = 1;
    do
    {
        system("cls");
        cout << ((choice == 1) ? "-->" : "   ") << "1. Display the list of students.\n";
        cout << ((choice == 2) ? "-->" : "   ") << "2. Add a new student to the list.\n";
        cout << ((choice == 3) ? "-->" : "   ") << "3. Remove a student from the list based on their student ID.\n";
        cout << ((choice == 4) ? "-->" : "   ") << "4. Update student information (full name, date of birth, GPA).\n";
        cout << ((choice == 5) ? "-->" : "   ") << "5. Find the student with the highest GPA.\n";
        cout << ((choice == 0) ? "-->" : "   ") << "0. Exit <3\n";
        char key = getch();
        switch (key)
        {
        case 72:
            choice = (choice == 0) ? 5 : choice - 1;
            break;
        case 80:
            choice = (choice == 5) ? 0 : choice + 1;
            break;
        case 13:
            switch (choice)
            {
            case 1:
                cout << "do " << choice << endl;
                break;
            case 2:
                cout << "do " << choice << endl;
                break;
            case 3:
                cout << "do " << choice << endl;
                break;
            case 4:
                cout << "do " << choice << endl;
                break;
            case 5:
                cout << "do " << choice << endl;
                break;
            case 0:
                cout << "Thanks for using <3" << endl;
                return 0;
                break;
            }
            system("pause");

            break;
        }

    } while (1);
    return 0;
}