#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct Node
{
    int value;
    Node *pNext;
};

struct LinkedList
{
    Node *pHead = NULL;
};

void traversal_node(LinkedList &l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        cout << p->value << " ";
        p = p->pNext;
    }
    cout << endl;
}

bool search_node(LinkedList &l, int x)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        if (p->value == x)
            return 1;
        p = p->pNext;
    }
    return 0;
}

bool isempty(LinkedList &l)
{
    return l.pHead == NULL;
}

int count_node(LinkedList &l)
{
    Node *p = l.pHead;
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->pNext;
    }
    return count;
}

void add_head(LinkedList &l, int data)
{
    Node *newHead = new Node;
    newHead->value = data;
    newHead->pNext = l.pHead;
    l.pHead = newHead;
}

void add_tail(LinkedList &l, int data)
{
    if (l.pHead == NULL)
    {
        add_head(l, data);
    }
    else
    {
        Node *p = l.pHead;
        while (p->pNext != NULL)
            p = p->pNext;
        Node *newTail = new Node;
        newTail->value = data;
        newTail->pNext = NULL;
        p->pNext = newTail;
    }
}

void remove_head(LinkedList &l)
{
    Node *Temp = l.pHead;
    l.pHead = l.pHead->pNext;
    delete Temp;
}

void remove_tail(LinkedList &l)
{
    if (l.pHead != NULL)
    {
        if (l.pHead->pNext == NULL) // 1 element
        {
            delete l.pHead;
            l.pHead = NULL;
        }
        else if (l.pHead->pNext->pNext == NULL) // 2 elements
        {
            Node *Temp = l.pHead->pNext;
            l.pHead->pNext = NULL;
            delete Temp;
        }
        else // other case
        {
            Node *p = l.pHead;
            while (p->pNext->pNext != NULL)
                p = p->pNext;
            Node *Temp = p;
        }
    }
}

void remove_duplicate(LinkedList &l)
{
    Node *p = l.pHead;
    while (p != NULL)
    {
        Node *p2 = p;
        while (p2->pNext != NULL) // warn
        {
            if (p2->pNext->value == p->value)
            {
                Node *Temp = p2->pNext;
                p2->pNext = p2->pNext->pNext;
                delete Temp;
            }
            else
            {
                p2 = p2->pNext;
            }
        }
        p = p->pNext;
    }
}
void delete_Linkedlist(LinkedList &l)
{
    while (l.pHead != NULL)
    {
        remove_head(l);
    }
}
int main()
{
    LinkedList a;
    int choice = 1;
    do
    {
        system("cls");
        cout << ((choice == 1) ? "-->" : "   ") << "1. Traversal nodes: Print the data of the linked list to console.\n";
        cout << ((choice == 2) ? "-->" : "   ") << "2. Search nodes: Search for a node by its value and print whether the node is found or not.\n";
        cout << ((choice == 3) ? "-->" : "   ") << "3. Check for emptiness: Check if the linked list is empty or not.\n";
        cout << ((choice == 4) ? "-->" : "   ") << "4. Count nodes: Count and return the total number of nodes in the linked list.\n";
        cout << ((choice == 5) ? "-->" : "   ") << "5. Add head: Append a new node at the beginning of the linked list.\n";
        cout << ((choice == 6) ? "-->" : "   ") << "6. Add tail: Append a new node at the end of the linked list.\n";
        cout << ((choice == 7) ? "-->" : "   ") << "7. Remove head: Delete the head node of the linked list.\n";
        cout << ((choice == 8) ? "-->" : "   ") << "8. Remove tail: Delete the tail node of the linked list.\n";
        cout << ((choice == 9) ? "-->" : "   ") << "9. Remove duplicate: Eliminate duplicate nodes in the linked list and keep only one of them.\n";
        cout << ((choice == 0) ? "-->" : "   ") << "0. Exit <3\n";
        char key = getch();
        switch (key)
        {
        case 72:
            choice--;
            if (choice < 0)
                choice = 9;
            break;
        case 80:
            choice++;
            if (choice > 9)
                choice = 0;
            break;
        case 13:
            switch (choice)
            {
            case 1:
                if (!isempty(a))
                    traversal_node(a);
                else
                    cout << "Linked list is empty!";
                break;
            case 2:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                {
                    cout << "Enter the value: ";
                    int n;
                    cin >> n;
                    if (search_node(a, n))
                        cout << "Found " << n << "!";
                    else
                        cout << "Not found!";
                }
                break;
            case 3:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                    cout << "Linked list is not empty!";
                break;
            case 4:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                    cout << count_node(a) << " node" << ((count_node(a) == 1) ? "!" : "s!");
                break;
            case 5:
            {
                cout << "Enter the value: ";
                int n;
                cin >> n;
                add_head(a, n);
            }
            break;
            case 6:
            {
                cout << "Enter the value: ";
                int n;
                cin >> n;
                add_tail(a, n);
            }
            break;
            case 7:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                {
                    remove_head(a);
                    cout << "Done!";
                }
                break;
            case 8:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                {
                    remove_tail(a);
                    cout << "Done!";
                }
                break;
            case 9:
                if (isempty(a))
                    cout << "Linked list is empty!";
                else
                {
                    remove_duplicate(a);
                    cout << "Done!";
                }
                break;
            case 0:
                delete_Linkedlist(a);
                cout << "Thank you <3";
                return 0;
            }
            cout << '\n';
            system("pause");
            break;
        }
    } while (1);
    return 0;
}