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
    cout << "Queue: ";
    Node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->pNext;
    }
    cout << endl;
}
void enqueue(LinkedList &l, int data)
{
    Node *newitem = new Node;
    newitem->value = data;
    newitem->pNext = l.pHead;
    l.pHead = newitem;
}
void dequeue(LinkedList &l)
{
    if (l.pHead->pNext == NULL) // n == 1
    {
        delete l.pHead;
        l.pHead = NULL;
    }
    else // n >= 2
    {
        Node *prep = l.pHead;
        Node *curp = l.pHead->pNext;
        while (curp->pNext != NULL)
        {
            prep = curp;
            curp = curp->pNext;
        }
        prep->pNext = NULL;
        delete curp;
    }
}
int front(LinkedList &l)
{
    Node *p = l.pHead;
    while (p->pNext != NULL)
    {
        p = p->pNext;
    }
    return p->value;
}
void delete_Linkedlist(LinkedList &l)
{
    while (l.pHead != NULL)
    {
        dequeue(l);
    }
}
int main()
{
    LinkedList a;
    int choice = 1;
    do
    {
        system("cls");
        cout << ((choice == 1) ? "-->" : "   ") << "1. enqueue: enqueue a new item into queue.\n";
        cout << ((choice == 2) ? "-->" : "   ") << "2. dequeue: dequeue the front item from the queue.\n";
        cout << ((choice == 3) ? "-->" : "   ") << "3. front: get the value of the front item.\n";
        cout << ((choice == 0) ? "-->" : "   ") << "0. Exit.\n";
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
                cout << "Enter value: ";
                int x;
                cin >> x;
                enqueue(a, x);
                break;
            case 2:
                if (a.pHead == NULL)
                    cout << "Empty queue!\n";
                else
                {
                    dequeue(a);
                    cout << "Done!\n";
                }
                break;
            case 3:
                if (a.pHead == NULL)
                    cout << "Empty queue!\n";
                else
                    cout << "Front item: " << front(a) << endl;
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