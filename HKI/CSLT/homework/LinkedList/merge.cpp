#include <iostream>
using namespace std;
struct Node
{
    int value;
    Node *pNext;
};
struct LinkedList
{
    int Count;
    Node *pHead;
    Node *pTail;
};
Node *createNode(int x)
{
    Node *newNode = new Node;
    newNode->value = x;
    newNode->pNext = NULL;
    return newNode;
}
void createLinkedList(LinkedList &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
    cout << "Number of element: ";
    cin >> l.Count;
    cout << "Input " << l.Count << " element of list: ";
    Node *p = l.pHead;
    for (int i = 0; i < l.Count; i++)
    {
        int data;
        cin >> data;
        Node *n = createNode(data);
        if (l.pHead == NULL)
        {
            l.pHead = n;
            p = n;
        }
        else
        {
            p->pNext = n;
            p = p->pNext;
        }
    }
    l.pTail = p;
}
void deleteLinkedList(LinkedList &l)
{
    while (l.pHead != NULL)
    {
        Node *temp = l.pHead;
        l.pHead = l.pHead->pNext;
        delete temp;
    }
    cout << l.pHead << endl;
    l.Count = 0;
    l.pTail = NULL;
}
void printLinkedList(LinkedList l)
{
    if (l.pHead != NULL)
    {
        Node *i = l.pHead;
        while (i != NULL)
        {
            cout << i->value << " ";
            i = i->pNext;
        }
        cout << endl;
    }
}
void sortLinkedlist(LinkedList l)
{
}
int main()
{
    LinkedList a, b;
    createLinkedList(a);
    createLinkedList(b);
    deleteLinkedList(a);
    deleteLinkedList(b);
    return 0;
}