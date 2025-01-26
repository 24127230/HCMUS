#include <iostream>
using namespace std;
struct Node
{
    int num;
    Node *next;
};
Node *createNode(int &data)
{
    Node *p = new Node;
    p->num = data;
    p->next = p;
    return p;
}
void addNode(Node *&head, int &data)
{
    if (head == NULL)
        head = createNode(data);
    else
    {
        Node *p = head;
        while (p->next != head)
            p = p->next;
        Node *pNew = createNode(data);
        pNew->next = head;
        p->next = pNew;
    }
}
int main()
{
    cout << "Input number of criminals: ";
    int n;
    cin >> n;
    if (n == 1)
        cout << "1";
    else
    {
        Node *head = NULL;
        for (int i = 1; i <= n; i++)
        {
            addNode(head, i);
        }
        Node *p = head;
        while (p->next != head)
        {
            p = p->next;
        }
        head = p;
        p = head->next;
        while (p->next->next != p)
        {
            Node *Temp = p->next;
            p->next = p->next->next;
            delete Temp;
            p = p->next;
        }
        cout << p->next->num << ", " << p->num;
        delete p->next;
        delete p;
    }
}