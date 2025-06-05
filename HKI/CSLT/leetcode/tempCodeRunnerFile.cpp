#include <iostream>
#include <string>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
void addTail(ListNode *&head, int n)
{
    if (!head)
    {
        head = new ListNode(n);
    }
    else
    {
        ListNode *p = head;
        while (p->next)
            p = p->next;
        p->next = new ListNode(n);
    }
}
void creatLL(string &s, ListNode *&head)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int num = s[i] - '0';
            addTail(head, num);
        }
    }
}
void displayLL(ListNode *&head)
{
    ListNode *p = head;
    cout << "[";
    while (p)
    {
        cout << p->val << ((p->next) ? "," : "");
        p = p->next;
    }
    cout << "]";
}
void deleteLL(ListNode *&head)
{
    while (head)
    {
        ListNode *t = head;
        head = head->next;
        delete t;
    }
}