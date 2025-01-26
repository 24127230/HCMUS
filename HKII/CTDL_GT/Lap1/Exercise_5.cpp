#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void PrintS(Node *head)
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

int SizeS(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

void PushS(Node *&head, int val)
{
    Node *pnew = new Node;
    pnew->data = val;
    pnew->next = head;
    head = pnew;
}

void PopS(Node *&head)
{
    if (!head)
        return;
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

bool IsEmptyS(Node *head)
{
    if (!head)
        return true;
    else
        return false;
}

Node *TopS(Node *&head)
{
    return head;
}

int main()
{
    Node *stack = NULL;
    PrintS(stack);

    cout << "Push(1): ";
    PushS(stack, 1);
    PrintS(stack);

    cout << "Push(2): ";
    PushS(stack, 2);
    PrintS(stack);

    cout << "Push(3): ";
    PushS(stack, 3);
    PrintS(stack);

    cout << "Top(): ";
    Node *top = TopS(stack);
    if (top)
        cout << top->data << "\n";
    else
        cout << "None top valid!\n";

    cout << "Pop(): ";
    PopS(stack);
    PrintS(stack);

    cout << "Empty(): " << IsEmptyS(stack) << '\n';

    while (!IsEmptyS(stack))
    {
        PopS(stack);
    }
    return 0;
}