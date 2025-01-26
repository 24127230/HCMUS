#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void PrintQ(Node *head)
{
    cout << '[';
    while (head)
    {
        cout << head->data;
        head = head->next;
        cout << ((head) ? ", " : "");
    }
    cout << ']';
    cout << '\n';
}

void Enqueue(Node *&head, int val)
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

void Dequeue(Node *&head)
{
    if (!head)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}
Node *Frontqueue(Node *&head)
{
    return head;
}

bool IsEmptyQ(Node *head)
{
    if (!head)
        return 1;
    else
        return 0;
}

int main()
{
    Node *queue = NULL;
    PrintQ(queue);

    cout << "Enqueue(1): ";
    Enqueue(queue, 1);
    PrintQ(queue);

    cout << "Enqueue(2): ";
    Enqueue(queue, 2);
    PrintQ(queue);

    cout << "Enqueue(3): ";
    Enqueue(queue, 3);
    PrintQ(queue);

    cout << "Front(): ";
    Node *fro = Frontqueue(queue);
    if (fro)
        cout << fro->data << '\n';
    else
        cout << "None front valid\n";
    
    cout << "Dequeue(): ";
    Dequeue(queue);
    PrintQ(queue);

    cout << "Empty(): " << IsEmptyQ(queue) << '\n';

    while(!IsEmptyQ(queue))
    {
        Dequeue(queue);
    }
    return 0;
}