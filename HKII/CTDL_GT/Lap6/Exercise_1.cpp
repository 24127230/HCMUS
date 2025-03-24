#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
};
Node *newNode(int data);
Node *insert(Node *root, int data);
Node *search(Node *root, int data);
Node *deleteNode(Node *root, int data);
void NLR(Node *root);
void LNR(Node *root);
void LRN(Node *root);
void LevelOrder(Node *root);

Node *newNode(int data)
{
    Node* node = new Node;
    node->key = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}
Node *insert(Node *root, int data)
{
    if (!root)
    {
        return newNode(data);
    }
    if (data < root->key)
        root->left = insert(root->left, data);
    else if (data > root->key)
        root->right = insert(root->right, data);
    return root;
}
Node *search(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data < root->key)
        return search(root->left, data);
    else if (data > root->key)
        return search(root->right, data);
    else return root;
}
Node *deleteNode(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data < root->key)
        root->left = deleteNode(root->left, data);
    else if (data > root->key)
        root->right = deleteNode(root->right, data);
    else {
        if (!root->left) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        Node* p = root->left;
        while (p && p->right)
            p = p->right;
        root->key = p->key;
        root->left = deleteNode(root->left, p->key);
    }
    return root;
}
void NLR(Node *root) {
    if (!root) return;
    cout << root->key << ' ';
    NLR(root->left);
    NLR(root->right);
}
void LNR(Node *root) {
    if (!root) return;
    LNR(root->left);
    cout << root->key << ' ';
    LNR(root->right);
}
void LRN(Node *root) {
    if (!root) return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << ' ';
}
void LevelOrder(Node *root) {
    if (!root) return;
    queue<Node*> a;
    a.push(root);
    while (!a.empty()) {
        Node* p = a.front();
        a.pop();
        cout << p->key << ' ';
        if (p->left) a.push(p->left);
        if (p->right) a.push(p->right);
    }
}

int main()
{
    vector<int> a = {10,5,2,7,1,3,15,12,11,13,20,18,22};
    Node* Root = NULL;
    for(int i : a)
    {
        Root = insert(Root, i);
    }
    cout << "Pre-order: "; NLR(Root); cout << '\n';
    cout << "In-order: "; LNR(Root); cout << '\n';
    cout << "Post-order: "; LRN(Root); cout << '\n';
    cout << "Level-order: "; LevelOrder(Root); cout << '\n';
    if (search(Root, 15)) {
        cout << "found 15\nthen delete 15\n";
        deleteNode(Root, 15);
    }
    else cout << "nfound\n";
    cout << "Pre-order: ";
    NLR(Root);
    // clear tree
    while (Root) {
        Root = deleteNode(Root, Root->key);
    }
    return 0;
}