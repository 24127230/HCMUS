#include <iostream>
using namespace std;

class Node {
public:
    int info;
    Node* pNext;
    Node();
    Node(int _info);
    Node(Node *_pNext, int _info);
    Node(Node *_pNext);
};

class LinkedList {
private:
    Node *pHead, *pTail;
    int curN;
public:
    LinkedList(void);
    ~LinkedList(void);

    static Node* CreateNode(const int& n);
    Node* AddHead(const int& n);
    Node* AddTail(const int& n);
    Node* RemoveHead();
    Node* RemoveTail();
    friend ostream& operator<<(ostream&, const LinkedList&);
    int& operator[](const int& i);
};

Node::Node(): pNext(NULL), info(0) {}
Node::Node(int _val): pNext(NULL), info(_val) {}
Node::Node(Node *_next, int _val): pNext(_next), info(_val) {}
Node::Node(Node *_next): pNext(_next), info(0) {}

LinkedList::LinkedList(): pHead(NULL), pTail(NULL), curN(0) {}
LinkedList::~LinkedList(void) {
    while (pHead) {
        RemoveHead();
    }
}

Node* LinkedList::CreateNode(const int& n) {
    return new Node(n);
}
Node* LinkedList::AddHead(const int& n) {
    Node *newHead = CreateNode(n);
    newHead->pNext = pHead;
    if (!pHead) { // Ll is null
        pHead = newHead;
        pTail = pHead;
    }
    else pHead = newHead;
    curN++;
    return pHead;
}
Node* LinkedList::AddTail(const int& n) {
    if(!pHead) return AddHead(n);
    Node *p = pHead;
    while(p->pNext) p = p->pNext;
    Node *newTail = CreateNode(n);
    p->pNext = newTail;
    pTail = newTail;
    curN++;
    return pHead;
}
Node* LinkedList::RemoveHead() {
    if(!pHead) return pHead;
    Node *Temp = pHead;
    pHead = pHead->pNext;
    delete Temp;
    if (!pHead) pTail = NULL;
    return pHead;
}
Node* LinkedList::RemoveTail() {
    if(!pHead) return pHead;
    if(!pHead->pNext) { //1 element
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        --curN;
        return pHead;
    }
    Node *p = pHead;
    while (p->pNext->pNext) p = p->pNext;
    delete p->pNext;
    p->pNext = NULL;
    pTail = p;
    --curN;
    return pHead;
}
ostream& operator<<(ostream& out, const LinkedList& ll) {
    Node *p = ll.pHead;
    while (p) {
        cout << p->info << ", ";
        p = p->pNext;
    }
    return out;
}
int& LinkedList::operator[](const int& i) {    
    if (!pHead) 
        throw std::out_of_range("Empty linked list");
    if (i <= 0) return pHead->info;
    if (i >= curN) return pTail->info;
    int index = 0;
    Node *p = pHead;
    while (p) {
        if (index++ == i) {
            return p->info;
        }
        p = p->pNext;
    }
}
int main()
{
    srand(1234);
    LinkedList l;
    for (int i = 0; i < 10; ++i)
    {
        if (rand() % 2 == 0)
        {
            l.AddHead(rand() % 1001);
        }
        else
        {
            l.AddTail(rand() % 1001);
        }
    }
    cout << l << endl;
    l.RemoveHead();
    l.RemoveTail();
    l[-1] = 9000;
    l[4] = 2000;
    l[100] = 10000;
    cout << l << endl;
    return 0;
}