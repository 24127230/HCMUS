#include <iostream>
#include <fstream>
#include <cstring>
#include <conio.h>
using namespace std;
struct student
{
    char fullName[50];
    char studentID[8];
    char dob[10];
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

bool isSameID(char a[], char b[])
{
    if (strlen(a) != strlen(b))
        return 0;
    for (int j = 0; j < strlen(a); j++)
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
    cin.getline(newstu->data.fullName, 50);
    cout << "Student ID                 : ";
    cin.getline(newstu->data.studentID, 8);
    cout << "Date of birth              : ";
    cin.getline(newstu->data.dob, 10);
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
        char ID[8];
        bool t = 0;
        cout << "Enter student ID: ";
        cin.getline(ID, 8);
        while (isSameID(l.pHead->data.studentID, ID))
        {
            t = 1;
            Node *Temp = l.pHead;
            l.pHead = l.pHead->pNext;
            delete Temp;
        }
        if (l.pHead != NULL)
        {
            Node *prep = l.pHead;
            Node *curp = l.pHead->pNext;
            while (curp != NULL)
            {
                if (isSameID(curp->data.studentID, ID))
                {
                    t = 1;
                    Node *Temp = curp;
                    curp = curp->pNext;
                    prep->pNext = curp;
                    delete Temp;
                }
                else
                {
                    prep = curp;
                    curp = curp->pNext;
                }
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
        char ID[8];
        bool t = 0;
        cout << "Enter student ID: ";
        cin.getline(ID, 8);
        Node *p = l.pHead;
        while (p != NULL)
        {
            if (isSameID(p->data.studentID, ID))
            {
                t = 1;
                cout << "Name                     : ";
                cin.getline(p->data.fullName, 50);
                cout << "Date of birth            : ";
                cin.getline(p->data.dob, 10);
                cout << "Grade Point Average (GPA): ";
                cin >> p->data.gpa;
            }
            p = p->pNext;
        }
        if (t)
            cout << "Updated\n";
        else
            cout << "No student ID exited\n";
        cin.ignore();
    }
}
void greatestGPA(LinkedList &l)
{
    if (l.pHead == NULL)
        cout << "No student!";
    else
    {
        double max = 0;
        Node *p = l.pHead;
        while (p != NULL)
        {
            max = (max < p->data.gpa) ? p->data.gpa : max;
            p = p->pNext;
        }
        cout << "Highest GPA: " << max << endl;
        p = l.pHead;
        while (p != NULL)
        {
            if (p->data.gpa == max)
            {
                cout << "Name         : " << p->data.fullName << endl;
                cout << "Student ID   : " << p->data.studentID << endl;
                cout << "Date of birth: " << p->data.dob << endl;
                cout << "----------------------------" << endl;
            }
            p = p->pNext;
        }
    }
}

void delete_Linkedlist(LinkedList &l)
{
    ofstream fout("file.dat", ios::binary);
    if (!fout.is_open())
        cerr << "Open file for append fail!";
    else
    {
        if (l.pHead != NULL)
        {
            Node *p = l.pHead;
            while (p != NULL)
            {
                // char na[50] = p.;
                // student stu = {name, p->data.studentID, p->data.dob, p->data.gpa};
                fout.write(reinterpret_cast<char *>(&p->data), sizeof(student));
                p = p->pNext;
            }
        }
        fout.close();
    }
    while (l.pHead != NULL)
    {
        Node *Temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete Temp;
    }
}
int main()
{

    LinkedList a;
    ifstream fin("file.dat", ios::binary);
    if (!fin.is_open())
    {
        cerr << "Open file for read fail!\nCoutinue!\n";
        system("pause");
    }
    student stu;
    while (fin.read(reinterpret_cast<char *>(&stu), sizeof(student)))
    {
        Node *newstudent = new Node;
        strcpy(newstudent->data.fullName, stu.fullName);
        strcpy(newstudent->data.studentID, stu.studentID);
        strcpy(newstudent->data.dob, stu.dob);
        newstudent->data.gpa = stu.gpa;
        if (a.pHead == NULL)
            a.pHead = newstudent;
        else
        {
            Node *p = a.pHead;
            while (p->pNext != NULL)
            {
                p = p->pNext;
            }
            p->pNext = newstudent;
        }
    }
    fin.close();
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
                displayList(a);
                break;
            case 2:
                add(a);
                break;
            case 3:
                removeByID(a);
                break;
            case 4:
                updateByID(a);
                break;
            case 5:
                greatestGPA(a);
                break;
            case 0:
                cout << "Thanks for using <3" << endl;
                delete_Linkedlist(a);
                return 0;
                break;
            }
            system("pause");

            break;
        }

    } while (1);
    return 0;
}