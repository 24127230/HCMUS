#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *pNext;
};

struct LinkedList
{
    Node *pHead;
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

bool emptiness(LinkedList &l)
{
    return l.pHead == NULL;
}

int count_node(LinkedList &l)
{
    Node *p = l.pHead;
    int count = 0;
    while (p != NULL)
    {
        cout++;
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
    Node *p = l.pHead;
    while (p->pNext != NULL)
        p = p->pNext;
    Node *newTail = new Node;
    newTail->value = data;
    newTail->pNext = NULL;
    p->pNext = newTail;
}

void remove_head(LinkedList &l)
{
    Node *Temp = l.pHead;
    l.pHead = l.pHead->pNext;
    delete Temp;
}

void remove_tail(LinkedList &l)
{
    if (l.pHead != NUll)
    {
        if (l)
        {
            /* code */
        }

        if (l.pHead->pNext == NULL)
        {
        }
        else
        {
            Node *p = l.pHead;
            while (p->pNext->pNext != NULL)
                p = p->pNext;
            Node *Temp = p;
        }
    }
}

int main()
{
    return 0;
}