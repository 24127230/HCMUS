#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    Node* R;
    Node* L;
    int value;
};

struct Tree
{
    Node* Root;
};

Node* createNode(int val) {
    Node* newNode = new Node;
    newNode->value = val;
    newNode-> L = NULL;
    newNode-> R = NULL;
    return newNode;
}
Node* insert(Node* Root, int val) {
    if (!Root) {
        Root = createNode(val);
        return Root;
    }
    if (val < Root->value) 
        Root->L = insert(Root->L, val);
    else if (val > Root->value)
        Root->R = insert(Root->R, val);

    return Root;
}
bool Search(Node* Root, int val) {
    if (!Root)
        return 0;
    if (val < Root->value) 
        Search(Root->L, val);
    else if (val > Root->value)
        Search(Root->R, val);
    return 1;
}
Node* find_predecessor(Node* node) {
    while (node && node->R != NULL) {
        node = node->R;
    }
    return node;
}
Node* delete_Node(Node* Root, int val) {
    if (!Root)   
        return Root;
    if (val < Root->value) Root->L = delete_Node(Root->L, val);
    else if (val > Root->value) Root->R = delete_Node(Root->R, val);
    else {
        if (!Root->L) {
            Node* temp = Root->R;
            delete Root;
            return temp;
        }
        else if (!Root->R) {
            Node* temp = Root->L;
            delete Root;
            return temp;
        }
        Node *p = find_predecessor(Root->L);
        Root->value = p->value;
        Root->L = delete_Node(Root->L, p->value);
    }
    return Root;
}
void inorder(Node* Root) {
    if(!Root) return;
    inorder(Root->L);
    cout << Root->value << " ";
    inorder(Root->R);
}
int main()
{
    vector<int> a = {15,5,12,8,23,1,17,21};
    Node* Root = NULL;
    for(int i : a) {
        Root = insert(Root, i);
    }
    // cout << "Exit 17: " << Search(Root, 17) << "\nThen try del 17\n";
    // cout << "Exit 17: " << Search(Root, 17) << '\n';
    inorder(Root);
    while (Root) 
    {
        Root = delete_Node(Root, Root->value);
    }
    inorder(Root);
    cout << "\ndone";
    return 0;
}