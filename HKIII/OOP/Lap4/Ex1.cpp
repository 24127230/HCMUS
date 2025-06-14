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
    friend ostream& operator<<(ostream& os, const LinkedList& ll);
    int& operator[](const int& i);
};

Node::Node(): next(NULL), val(0) {}
Node::Node(int _val): next(NULL), val(_val) {}
Node::Node(Node *_next, int _val): next(_next), val(_val) {}
Node::Node(Node *_next): next(_next), val(0) {}

LinkedList::LinkedList(): pHead(NULL), pTail(NULL), curN(0) {}
~LinkedList(void);

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
    else {
        Node *p = pHead;
        while(p->pNext) p = p->pNext;
        Node *newTail = CreateNode(n);
        p->pNext = newTail;
        pTail = newTail;
        curN++;
        return pHead;
    }
}
Node* LinkedList::RemoveHead() {
    if(!pHead) return pHead;
    if(!pHead->pNext) { //1 element
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        curN--;
        return pHead;
    }
    Node *Temp = pHead;
    pHead = pHead->pNext;
    delete Temp;
    --curN;
    return pHead;
}
Node* LinkedList::RemoveTail() {
    if(pHead) {
        if(!pHead->pNext) { //1 element
            delete pHead;
            pHead = NULL;
            pTail = NULL;
        }
        else {
            Node *p = pHead;
            while (p->pNext->pNext) p = p->pNext;
            delete p->pNext;
            p->pNext = NULL;
            pTail = p;
        }
    }
    --curN;
    return pHead;
}
friend ostream& operator<<(ostream& os, const LinkedList& ll);
int& operator[](const int& i);


int main()
{
    // srand(1234);
    // LinkedList l;
    // for (int i = 0; i < 10; ++i)
    // {
    //     if (rand() % 2 == 0)
    //     {
    //         l.AddHead(rand() % 1001);
    //     }
    //     else
    //     {
    //         l.AddTail(rand() % 1001);
    //     }
    // }
    // cout << l << endl;
    // l.RemoveHead();
    // l.RemoveTail();
    // l[-1] = 9000;
    // l[4] = 2000;
    // l[100] = 10000;
    // cout << l << endl;
    return 0;
}