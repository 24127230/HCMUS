#include <iostream>
using namespace std;
struct Node
{
    int k;
    Node *n;
    Node() : k(0), n(NULL) {}
    Node(int x) : k(x), n(NULL) {}
    Node(int x, Node *n) : k(x), n(n) {}
};
void pri(Node *&head)
{
    Node *p = head;
    while (p)
    {
        cout << p->k << " -> ";
        p = p->n;
    }
    cout << "null\n";
}
void del(Node *&head)
{
    while (head)
    {
        Node *Temp = head;
        head = head->n;
        delete Temp;
    }
}
void addTail(Node *&head, int n)
{
    if (!head)
    {
        head = new Node(n);
    }
    else
    {
        Node *p = head;
        while (p->n)
            p = p->n;
        p->n = new Node(n);
    }
}
Node *push(Node *&head, int x)
{
    Node *newN = new Node;
    newN->k = x;
    newN->n = head;
    head = newN;
    return head;
}
Node *buildOneTwoThree()
{
    Node *chained = nullptr;
    chained = push(chained, 3); // Linked list becomes: 3 -> null
    pri(chained);
    chained = push(chained, 2); // Linked list becomes: 2 -> 3 -> null
    pri(chained);
    chained = push(chained, 1); // Linked list becomes: 1 -> 2 -> 3 -> null
    pri(chained);
    // Final linked list: 1 -> 2 -> 3 -> null
    return chained;
}
int length(Node *head)
{
    if (!head)
        return 0;
    return length(head->n) + 1;
}
int count(Node *head, int target)
{
    if (!head)
        return 0;
    return ((head->k == target) ? 1 : 0) + count(head->n, target);
}
void getNth(Node *&head, int index)
{
    if(!head) cout << "Linked list is empty\n";
    else
    {
        Node *p = head;
        while (index)
        {
            index--;
            p = p->n;
            if(!p)
            {
                cout << "Node don't exit!\n";
                return;
            }
        }
        cout << p->k << endl;
    }
}
Node *InsertNth(Node *&head, int index, int n)
{
    if (index > length(head))
        cout << "Invailid index!\n";
    else
    {
        if (!index)
        {
            head = push(head, n);
        }
        else
        {
            Node *p = head;
            while (index != 1)
            {
                index--;
                p = p->n;
            }
            p->n = push(p->n, n);
        }
    }
    return head;
}
void reverse(Node *&head)
{
    if(head)
    {
        Node * p = head;
        Node * pp = p->n;
        p->n = NULL;
        while(pp)
        {
            Node * t = pp->n;
            pp->n = p;
            p = pp;
            pp = t;
        }
        head = p;
    }
}
void Recursive_reverse(Node *p, Node *&head)
{
    if(head){
        if(!p->n)
        {
            head = p;
            return;
        }
        Recursive_reverse(p->n, head);
        Node *q = p->n;
        q->n = p;
        p->n = NULL;
    }
}
int *listToArray(Node *&head)
{
    int * array = new int[length(head)];
    Node *p = head;
    int i = 0;
    while(p)
    {
        array[i++] = p->k;
        p = p->n;
    }
    return array;
}
int main()
{
    return 0;
}