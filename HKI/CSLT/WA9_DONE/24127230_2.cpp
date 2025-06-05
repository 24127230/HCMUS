#include <iostream>
#include <string>
#include <conio.h>
using namespace std;
struct Node
{
    std::string playerName;
    Node *next;
};
Node *createNode(const std::string &playerName);
void addPlayer(Node *&head, const std::string &playerName);
void displayCurrentPlayer(Node *current);
void moveToNextPlayer(Node *&current);
void deleteList(Node *&head);
int main()
{
    int choice = 1;
    Node *head = NULL;
    Node *current = NULL;
    do
    {
        system("cls");
        if (current == NULL)
            current = head;
        displayCurrentPlayer(current);
        cout << ((choice == 1) ? "-->" : "   ") << "Move to next player\n";
        cout << ((choice == 2) ? "-->" : "   ") << "Add player\n";
        cout << ((choice == 3) ? "-->" : "   ") << "Exit\n";
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
                moveToNextPlayer(current);
                break;
            case 2:
            {
                cout << "Enter name: ";
                string a;
                getline(cin, a);
                addPlayer(head, a);
                break;
            }
            case 3:
                deleteList(head);
                cout << "Thanks";
                return 0;
                break;
            }
            break;
        }
    } while (1);
}

Node *createNode(const std::string &playerName)
{
    Node *p = new Node;
    p->playerName = playerName;
    p->next = p;
    return p;
}
void addPlayer(Node *&head, const std::string &playerName)
{
    if (head == NULL)
        head = createNode(playerName);
    else
    {
        Node *p = head;
        while (p->next != head)
            p = p->next;
        Node *pNew = createNode(playerName);
        pNew->next = head;
        p->next = pNew;
    }
}
void displayCurrentPlayer(Node *current)
{
    if (current == NULL)
    {
        cout << "----No player, please add some----\n";
    }
    else
    {
        cout << current->playerName << "'s turn\n";
    }
}
void moveToNextPlayer(Node *&current)
{
    if (current == NULL)
    {
        cout << "No player!\n";
        system("pause");
    }
    else
    {
        current = current->next;
    }
}
void deleteList(Node *&head)
{
    Node *p = head->next;
    head->next = NULL;
    while (p != NULL)
    {
        Node *Temp = p;
        p = p->next;
        delete Temp;
    }
}