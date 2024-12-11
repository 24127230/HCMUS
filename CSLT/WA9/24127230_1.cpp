#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct Node
{
    std::string imageName;
    Node *next;
    Node *prev;
};
Node *createNode(const std::string &imageName);
void addImage(Node *&head, Node *&current, const std::string &imageName);
void displayCurrentImage(Node *current);
void moveNext(Node *&current);
void movePrevious(Node *&current);
void deleteList(Node *head);
int main()
{
    Node *head = NULL;
    Node *current = NULL;
    int choice = 1;
    do
    {
        system("cls");
        cout << "Name of the image: ";
        displayCurrentImage(current);
        cout << ((choice == 1) ? "-->" : "   ") << "Next\n";
        cout << ((choice == 2) ? "-->" : "   ") << "Previous\n";
        cout << ((choice == 3) ? "-->" : "   ") << "Add image\n";
        cout << ((choice == 4) ? "-->" : "   ") << "Exit\n";
        char key = getch();
        switch (key)
        {
        case 72:
            choice = (choice == 1) ? 4 : choice - 1;
            break;
        case 80:
            choice = (choice == 4) ? 1 : choice + 1;
            break;
        case 13:
            switch (choice)
            {
            case 1:
                if (current == NULL)
                {
                    cout << "No image!\n";
                    system("pause");
                }
                else
                    moveNext(current);
                break;
            case 2:
                if (current == NULL)
                {
                    cout << "No image!\n";
                    system("pause");
                }
                else
                    movePrevious(current);
                break;
            case 3:
            {
                cout << "Enter new image: ";
                string a;
                getline(cin, a);
                addImage(head, current, a);
                break;
            }
            case 4:
                deleteList(head);
                cout << "Thanks\n";

                system("pause");
                return 0;
                break;
            }
            break;
        }
    } while (1);
}
Node *createNode(const string &imageName)
{
    Node *newnode = new Node;
    newnode->imageName = imageName;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}
void addImage(Node *&head, Node *&current, const string &imageName)
{
    if (head == NULL)
    {
        Node *pNew = createNode(imageName);
        head = pNew;
        current = pNew;
    }
    else
    {
        Node *pNew = createNode(imageName);
        if (current->next != NULL)
        {
            pNew->next = current->next;
            pNew->next->prev = pNew;
        }
        current->next = pNew;
        pNew->prev = current;
    }
}

void displayCurrentImage(Node *current)
{
    if (current == NULL)
        cout << "(No image)\n";
    else
        cout << current->imageName << endl;
}

void moveNext(Node *&current)
{
    if (current->next == NULL)
    {
        cout << "No image next!\n";
        system("pause");
    }
    else
        current = current->next;
}
void movePrevious(Node *&current)
{
    if (current->prev == NULL)
    {
        cout << "No image previous!\n";
        system("pause");
    }
    else
        current = current->prev;
}
void deleteList(Node *head)
{
    while (head != NULL)
    {
        Node *Temp = head;
        head = head->next;
        delete Temp;
    }
}