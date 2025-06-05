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
ListNode *addTwoNumbers(ListNode *&l1, ListNode *&l2)
{
    ListNode *res = NULL;
    int du = 0;
    ListNode *a = l1;
    ListNode *b = l2;
    while (a || b)
    {
        int suba = (a) ? a->val : 0;
        int subb = (b) ? b->val : 0;

        addTail(res, (suba + subb + du) % 10);
        du = (suba + subb + du) / 10;
        if (a)
        {
            a = a->next;
        }
        if (b)
        {
            b = b->next;
        }
    }
    if (du)
        addTail(res, du);
    return res;
}
int main()
{
    string a, b;
    ListNode *ahead = NULL;
    ListNode *bhead = NULL;
    getline(cin, a);
    getline(cin, b);
    creatLL(a, ahead);
    creatLL(b, bhead);
    ListNode *res = addTwoNumbers(ahead, bhead);
    deleteLL(ahead);
    deleteLL(bhead);
    displayLL(res);
    deleteLL(res);
    return 0;
}