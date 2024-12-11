#include <iostream>
#include <conio.h>
using namespace std;
struct Node
{
    int value = 0;
    Node *pNext = NULL;
};
struct LinkedList
{
    Node *pHead = NULL;
};
void traversal_node(LinkedList &l)
{
    cout << "Stack: ";
    Node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->pNext;
    }
    cout << endl;
}
void push_stack(LinkedList &l, int data)
{
    Node *newHead = new Node;
    newHead->pNext = l.pHead;
    newHead->value = data;
    l.pHead = newHead;
}
void pop_stack(LinkedList &l)
{
    Node *Temp = l.pHead;
    l.pHead = l.pHead->pNext;
    delete Temp;
}
int top_stack(LinkedList &l)
{
    return l.pHead->value;
}
void delete_Linkedlist(LinkedList &l)
{
    while (l.pHead != NULL)
    {
        pop_stack(l);
    }
}
int main()
{
    LinkedList a;
    int choice = 1;
    do
    {
        system("cls");
        cout << ((choice == 1) ? "-->" : "   ") << "1. push: push a new item into stack.\n";
        cout << ((choice == 2) ? "-->" : "   ") << "2. pop: pop the top item from the stack.\n";
        cout << ((choice == 3) ? "-->" : "   ") << "3. top: get the value of the top item.\n";
        cout << ((choice == 0) ? "-->" : "   ") << "0. Exit\n";
        char key = getch();
        switch (key)
        {
        case 72:
            choice = (choice == 0) ? 3 : choice - 1;
            break;
        case 80:
            choice = (choice == 3) ? 0 : choice + 1;
            break;
        case 13:
            switch (choice)
            {
            case 1:
                int x;
                cout << "Enter value: ";
                cin >> x;
                push_stack(a, x);
                break;
            case 2:
                if (a.pHead == NULL)
                    cout << "Empty stack!\n";
                else
                {
                    pop_stack(a);
                    cout << "Done!\n";
                }
                break;
            case 3:
                if (a.pHead == NULL)
                    cout << "Empty stack!\n";
                else
                    cout << "Top stack: " << top_stack(a) << endl;
                break;
            case 0:
                delete_Linkedlist(a);
                cout << "Thanks <3\n";
                return 0;
                break;
            }
            system("pause");
            break;
        }
    } while (1);
    return 0;
}