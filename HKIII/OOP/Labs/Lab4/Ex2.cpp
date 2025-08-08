#include <iostream>
#include <cmath>
using namespace std;
#define MAXLEN 100
class Node
{
public:
    int info;
    Node *pNext;
    Node();
    Node(int _info);
};
class LinkedList
{
private:
    Node *pHead, *pTail;
    int curN;

public:
    LinkedList(void);
    ~LinkedList(void);
    static Node *CreateNode(const int &n);
    Node *AddHead(const int &n);
    Node *AddTail(const int &n);
    Node *RemoveHead();
    Node *RemoveTail();
    friend ostream &operator<<(ostream &, const LinkedList &);
    int &operator[](const int &i);
    Node* get_head() { return pHead; }
    Node* get_tail() { return pTail; }
    void reverseLL() {
        Node* prev = NULL;
        Node* current = pHead;
        Node* next = NULL;

        while (current) {
            next = current->next; // Lưu node tiếp theo
            current->next = prev; // Đảo ngược con trỏ
            prev = current;       // Di chuyển prev và current lên một bước
            current = next;
        }
        pHead = prev;
    }
};
Node::Node() : pNext(NULL), info(0) {}
Node::Node(int _val) : pNext(NULL), info(_val) {}
LinkedList::LinkedList() : pHead(NULL), pTail(NULL), curN(0) {}
LinkedList::~LinkedList(void)
{
    while (pHead)
    {
        RemoveHead();
    }
}
Node *LinkedList::CreateNode(const int &n)
{
    return new Node(n);
}
Node *LinkedList::AddHead(const int &n)
{
    Node *newHead = CreateNode(n);
    newHead->pNext = pHead;
    if (!pHead)
    { // Ll is null
        pHead = newHead;
        pTail = pHead;
    }
    else
        pHead = newHead;
    curN++;
    return pHead;
}
Node *LinkedList::AddTail(const int &n)
{
    if (!pHead)
        return AddHead(n);
    Node *p = pHead;
    while (p->pNext)
        p = p->pNext;
    Node *newTail = CreateNode(n);
    p->pNext = newTail;
    pTail = newTail;
    curN++;
    return pHead;
}
Node *LinkedList::RemoveHead()
{
    if (!pHead)
        return pHead;
    Node *Temp = pHead;
    pHead = pHead->pNext;
    delete Temp;
    if (!pHead)
        pTail = NULL;
    return pHead;
}
Node *LinkedList::RemoveTail()
{
    if (!pHead)
        return pHead;
    if (!pHead->pNext)
    { // 1 element
        delete pHead;
        pHead = NULL;
        pTail = NULL;
        --curN;
        return pHead;
    }
    Node *p = pHead;
    while (p->pNext->pNext)
        p = p->pNext;
    delete p->pNext;
    p->pNext = NULL;
    pTail = p;
    --curN;
    return pHead;
}
ostream &operator<<(ostream &out, const LinkedList &ll)
{
    Node *p = ll.pHead;
    while (p)
    {
        cout << p->info << ", ";
        p = p->pNext;
    }
    return out;
}
int &LinkedList::operator[](const int &i)
{
    if (!pHead)
        throw std::out_of_range("Empty linked list");
    if (i <= 0)
        return pHead->info;
    if (i >= curN)
        return pTail->info;
    int index = 0;
    Node *p = pHead;
    while (p)
    {
        if (index++ == i)
        {
            return p->info;
        }
        p = p->pNext;
    }
}

class SoNguyenLon
{
private:
    LinkedList mangSo;
    int soCS;
    // static SoNguyenLon snlMax;

public:
    SoNguyenLon(void);
    SoNguyenLon(int cs, int scs);
    SoNguyenLon(const unsigned int &n);
    SoNguyenLon(const SoNguyenLon &snl);
    ~SoNguyenLon(void);
    SoNguyenLon operator+(const SoNguyenLon &snl);
    SoNguyenLon operator-(const SoNguyenLon &snl);
    bool operator>(const SoNguyenLon &snl);
    const SoNguyenLon &operator=(const SoNguyenLon &snl);
    friend SoNguyenLon operator+(const unsigned int &n, const SoNguyenLon &snl);
    friend SoNguyenLon operator-(const unsigned int &n, const SoNguyenLon &snl);
    friend ostream &operator<<(ostream &os, const SoNguyenLon &snl);
    static SoNguyenLon SNLMax();
    LinkedList get_mangSo() { return mangSo; }
};

SoNguyenLon::SoNguyenLon(void)
{
    soCS = 1;
    mangSo.AddHead(0);
}
SoNguyenLon::SoNguyenLon(int cs, int scs)
{
    if (cs < 1)
        cs = 1;
    if (cs > 9)
        cs = 9;
    soCS = abs(scs);
    if (soCS < 1)
        soCS = 1;
    // if (soCS > MAXLEN)
    // {
    //     soCS = MAXLEN;
    // }
    for (int i = 0; i < soCS; ++i)
    {
        mangSo.AddTail(cs);
    }
    // if (*this > snlMax)
    // {
    //     snlMax = *this;
    // }
}
SoNguyenLon::SoNguyenLon(const unsigned int &n)
{
    unsigned int temp = n;
    soCS = 0;
    while (temp > 9)
    {
        mangSo.AddTail(temp % 10);
        temp /= 10;
        ++soCS;
    }
    mangSo.AddTail(temp);
    ++soCS;
    // if (*this > snlMax)
    // {
    //     snlMax = *this;
    // }
}
SoNguyenLon::SoNguyenLon(const SoNguyenLon &snl)
{
    soCS = snl.soCS;
    Node *p = snl.get_mangSo().get_head();
    while (p) {
        mangSo.AddTail(p->info);
        p = p->pNext;
    }
}
SoNguyenLon::~SoNguyenLon(void)
{
}
bool SoNguyenLon::operator>(const SoNguyenLon &snl)
{
    if (soCS > snl.soCS)
    {
        return true;
    }
    if (soCS < snl.soCS)
    {
        return false;
    }
    this->mangSo.reverseLL();
    snl.mangSo.reverseLL();
    Node* p1 =this->mangSo.get_head();
    Node* p2 =snl.mangSo.get_head();
    while(p1)
    {
        if (p1 == p2)
        {
            p1 = p1->pNext;
            p2 = p2->pNext;
        }
        if (p1 > p2)
        {
            this->mangSo.reverseLL();
            snl.mangSo.reverseLL();
            return true;
        }
        this->mangSo.reverseLL();
        snl.mangSo.reverseLL();
        return false;
    }
    
    this->mangSo.reverseLL();
    snl.mangSo.reverseLL();
    return false;
}


const SoNguyenLon &SoNguyenLon::operator=(const SoNguyenLon &snl)
{
    soCS = snl.soCS;

    while(mangSo.get_head()) mangSo.RemoveHead();
    Node* p = snl.mangSo.get_head();
    while(p)
    {
        mangSo.AddTail(p->info);
    }
    return *this;
}
SoNguyenLon SoNguyenLon::operator+(const SoNguyenLon &snl)
{
    SoNguyenLon snlKQ;
    const SoNguyenLon *snlSCSMax = (soCS > snl.soCS) ? this : &snl;
    const SoNguyenLon *snlSCSMin = (soCS < snl.soCS) ? this : &snl;
    int soCSMin = (soCS > snl.soCS) ? snl.soCS : soCS;
    Node* i =this->mangSo.get_head();
    Node* j =snl.mangSo.get_head();

    int carry = 0;
    while (i || j || carry) {
        int this_ = (i) ? i->info : 0;
        int snl_ = (j) ? j->info : 0;
        i = i->pNext;
        j = j->pNext;
        snlKQ.mangSo.AddTail(this_ + snl_ + carry);
        carry = sum / 10;
    }
    // for (int i = 0; i < snlSCSMin->soCS; ++i)
    // {
    //     snlKQ.mangSo[i] = mangSo[i] + snl.mangSo[i] + nho;
    //     nho = snlKQ.mangSo[i] / 10;
    //     snlKQ.mangSo[i] %= 10;
    // }
    // for (int i = snlSCSMin->soCS; i < snlSCSMax->soCS; ++i)
    // {
    //     snlKQ.mangSo[i] = snlSCSMax->mangSo[i] + nho;
    //     nho = snlKQ.mangSo[i] / 10;
    //     snlKQ.mangSo[i] %= 10;
    // }
    // snlKQ.soCS = snlSCSMax->soCS;
    // if (nho > 0)
    // {
    //     snlKQ.mangSo[snlKQ.soCS++] = 1;
    // }
    // if (snlKQ > snlMax)
    // {
    //     snlMax = snlKQ;
    // }
    return snlKQ;
}
SoNguyenLon SoNguyenLon::operator-(const SoNguyenLon &snl)
{
    SoNguyenLon snlKQ;

    int carry = 0;
    if (snl > *this) return snlKQ;
    while(soCS > snl.soCS) {
        snl.mangSo.AddTail(0);
        ++snl.soCS;
    }
    Node* i =this->mangSo.get_head();
    Node* j =snl.mangSo.get_head();
    while (i) {
        int this_ = i->info;
        int snl_ = j->pNext + carry;
        i = i->pNext;
        j = j->pNext;
        if (this_ < snl_) {
            this_ += 10;
            carry = 1;
        }
        else   
            carry = 0;
        snlKQ.mangSo.AddTail(this_-snl_);
        snlKQ.soCS++;
    }
    while (snlKQ > 1 && res[0] == '0') res.erase(0, 1);
    return snlKQ;

    // if (soCS >= snl.soCS)
    // {
    //     for (i = 0; i < snl.soCS; ++i)
    //     {
    //         snlKQ.mangSo[i] = mangSo[i] - snl.mangSo[i] - nho;
    //         nho = 0;
    //         if (snlKQ.mangSo[i] < 0)
    //         {
    //             snlKQ.mangSo[i] += 10;
    //             nho = 1;
    //         }
    //     }
    //     for (; i < soCS; ++i)
    //     {
    //         snlKQ.mangSo[i] = mangSo[i] - nho;
    //         nho = 0;
    //         if (snlKQ.mangSo[i] < 0)
    //         {
    //             snlKQ.mangSo[i] += 10;
    //             nho = 1;
    //         }
    //     }
    //     snlKQ.soCS = soCS;
    //     while (snlKQ.mangSo[snlKQ.soCS - 1] == 0)
    //     {
    //         snlKQ.soCS--;
    //     }
    // }
    return snlKQ;
}
SoNguyenLon operator+(const unsigned int &n, const SoNguyenLon &snl)
{
    SoNguyenLon snlTemp(n);
    SoNguyenLon snlKQ = snlTemp + snl;
    if (snlKQ > SoNguyenLon::snlMax)
    {
        SoNguyenLon::snlMax = snlKQ;
    }
    return snlKQ;
}
SoNguyenLon operator-(const unsigned int &n, const SoNguyenLon &snl)
{
    SoNguyenLon snlTemp(n);
    return snlTemp - snl;
}
ostream &operator<<(ostream &os, const SoNguyenLon &snl)
{
    for (int i = snl.soCS - 1; i >= 0; --i)
    {
        os << snl.mangSo[i];
    }
    return os;
}

int main()
{
    SoNguyenLon snl1;
    SoNguyenLon snl2(44667733);
    SoNguyenLon snl3(5, 9);
    SoNguyenLon snl4(7, 30);
    SoNguyenLon snl5 = snl3 - snl2;
    SoNguyenLon snl6 = 1098765432 - snl2;
    SoNguyenLon snl7 = snl4 - snl3 + 123456789;
    SoNguyenLon snl8 = snl2 * snl3;
    cout << snl1 << endl
         << snl2 << endl
         << snl3 << endl;
    cout << snl4 << endl
         << snl5 << endl
         << snl6 << endl;
    cout << snl7 << endl
         << snl8 << endl
         << endl;
    return 0;
}