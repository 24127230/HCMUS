#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void traversalNode(Node *head)
{
    while (head)
    {
        cout << head->data << ' ';
        head = head->next;
    }
    cout << '\n';
}

int countNode(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void addhead(Node *&head, int val)
{
    Node *pnew = new Node;
    pnew->data = val;
    pnew->next = head;
    head = pnew;
}

void addtail(Node *&head, int val)
{
    Node *pnew = new Node;
    pnew->data = val;
    pnew->next = NULL;

    if (!head)
        head = pnew;
    else
    {
        Node *p = head;
        while (p->next)
        {
            p = p->next;
        }
        p->next = pnew;
    }
}

void removehead(Node *&head)
{
    if (!head)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

void removetail(Node *&head)
{
    if (!head)
        return;
    Node *prep = NULL;
    Node *p = head;
    while (p->next)
    {
        prep = p;
        p = p->next;
    }
    delete p;
    if (!prep)
        head = NULL;
    else
        prep->next = NULL;
}

void removeduplicate(Node *&head)
{
    if (!head)
        return;
    Node *p = head;
    while (p)
    {
        int datap = p->data;
        Node *presubp = NULL;
        Node *subp = p->next;
        while (subp)
        {
            if (subp->data == datap)
            {
                Node *temp = subp;
                subp = subp->next;
                if (!presubp)
                    p->next = subp;
                else
                    presubp->next = subp;
                delete temp;
            }
            else
            {
                presubp = subp;
                subp = subp->next;
            }
        }
        p = p->next;
    }
}

int main()
{
    Node *head = NULL;
    cout << "Add node head 1 - 5:\n";
    for (int i = 1; i <= 5; i++)
    {
        addhead(head, i);
    }
    traversalNode(head);

    cout << "Add node tail 1 - 3;\n";
    for (int i = 1; i <= 3; i++)
    {
        addtail(head, i);
    }
    traversalNode(head);

    cout << "Remove head and tail:\n";
    removehead(head);
    removetail(head);
    traversalNode(head);

    cout << "Remove duplicate node:\n";
    removeduplicate(head);
    traversalNode(head);

    cout << "Count node: " << countNode(head);

    while(head)
        removehead(head);
    return 0;
}