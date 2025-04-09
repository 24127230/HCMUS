#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};
// Exercise 1
Node *newNode(int data)
{
    Node *nNode = new Node;
    nNode->height = 1;
    nNode->key = data;
    nNode->left = NULL;
    nNode->right = NULL;
    return nNode;
}
int height(Node *root)
{
    if (!root)
        return 0;
    return root->height;
}
int balance(Node *root)
{
    if (!root)
        return 0;
    return (height(root->left) - height(root->right));
}
Node *LRotate(Node *root)
{
    Node *newroot = root->right;
    root->right = newroot->left;
    newroot->left = root;
    root->height = 1 + max(height(root->right), height(root->left));
    newroot->height = 1 + max(height(newroot->right), height(newroot->left));
    return newroot;
}
Node *RRotate(Node *root)
{
    Node *newroot = root->left;
    root->left = newroot->right;
    newroot->right = root;
    root->height = 1 + max(height(root->right), height(root->left));
    newroot->height = 1 + max(height(newroot->right), height(newroot->left));
    return newroot;
}
Node *insertNode(Node *root, int data)
{
    if (!root)
        root = newNode(data); 
    else {
        if (root->key == data)
            return root;
        if (root->key > data)
            root->left = insertNode(root->left, data);
        else
            root->right = insertNode(root->right, data);
    }

    root->height = 1 + max(height(root->right), height(root->left));
    int bf = balance(root);
    if (bf > 1 && balance(root->left) > 0) // LL
        return RRotate(root);
    if (bf > 1 && balance(root->left) < 0) // LR
    {
        root->left = LRotate(root->left);
        return RRotate(root);
    }
    if (bf < -1 && balance(root->right) < 0) // RR
        return LRotate(root);
    if (bf < -1 && balance(root->right) > 0) // RL
    {
        root->right = RRotate(root->right);
        return LRotate(root);
    }
    return root;
}
Node *searchNode(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data < root->key)
        return searchNode(root->left, data);
    else if (data > root->key)
        return searchNode(root->right, data);
    else
        return root;
}
Node *deleteNode(Node *root, int data)
{
    if (!root)
        return NULL;
    if (data < root->key)
        root->left = deleteNode(root->left, data);
    else if (data > root->key)
        root->right = deleteNode(root->right, data);
    else
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *p = root->left;
        while (p && p->right)
            p = p->right;
        root->key = p->key;
        root->left = deleteNode(root->left, p->key);
    }
    if (!root)
        return root;
    root->height = 1 + max(height(root->left), height(root->right));
    int bf = balance(root);
    if (bf > 1 && balance(root->left) >= 0) //LL
        return RRotate(root);
    if (bf > 1 && balance(root->left) < 0) // LR
    {
        root->left = LRotate(root->left);
        return RRotate(root);
    }
    if (bf < -1 && balance(root->right) <= 0) // RR
        return LRotate(root);
    if (bf < -1 && balance(root->right) > 0) // RL
    {
        root->right = RRotate(root->right);
        return LRotate(root);
    }
    return root;
}
void NLR(Node *root)
{
    if (!root)
        return;
    cout << root->key << ' ';
    NLR(root->left);
    NLR(root->right);
}
void LNR(Node *root)
{
    if (!root)
        return;
    LNR(root->left);
    cout << root->key << ' ';
    LNR(root->right);
}
void LRN(Node *root)
{
    if (!root)
        return;
    LRN(root->left);
    LRN(root->right);
    cout << root->key << ' ';
}
void LevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> a;
    a.push(root);
    while (!a.empty())
    {
        Node *p = a.front();
        a.pop();
        cout << p->key << ' ';
        if (p->left)
            a.push(p->left);
        if (p->right)
            a.push(p->right);
    }
}

// Exercise 2
bool isFull(Node* root) {
    if (!root) return 1;
    if ((!root->left) ^ (!root->right)) return 0;
    return (isFull(root->left) && isFull(root->right));
}
bool isComplete(Node* root) {
    if (!root) return 1;
    queue<Node*> a;
    bool must_be_leaf = 0;
    a.push(root);
    while (!a.empty()) 
    {
        Node *node = a.front(); a.pop();
        if (node->left) {
            if (must_be_leaf)
                return 0;
            a.push(node->left);
        } 
        else must_be_leaf = 1;
        if (node->right) {
            if (must_be_leaf)
                return 0;
            a.push(node->right);
        } 
        else must_be_leaf = 1;
    }
    return 1;
}
bool isPerfect(Node* root) {
    if (!root) 
        return 1;
    int height = 0;
    Node *p = root;
    while (p) {
        height++;
        p = p->left;
    }
    queue<pair<Node*, int>> q;
    q.push({root, 1});
    while (!q.empty()) {
        Node* node = q.front().first;
        int level = q.front().second;
        q.pop();
        if (!node->left && !node->right) // mean its leaf
            if (level != height) return 0;
        if ((!node->left) ^ (!node->right)) return 0;
        if (node->left) q.push({node->left, level + 1});
        if (node->right) q.push({node->right, level + 1});
    }
    return 1; 
}
void printSpecialNodes(Node* root) { //Find all nodes with 2 child nodes, and the left child is a divisor of the right child. Print them to the console in ascending order.    
    if (!root)
        return;
    printSpecialNodes(root->left);
    if (root->left && root->right && root->right->key % root->left->key == 0) 
        cout << root->key << ' ';
    printSpecialNodes(root->right);
}

int main()
{
    vector<int> a = {1,2,3,5,6,7,8,10,11,12,13,15,16,18,19};
    Node *Root = NULL;
    for (int i : a)
    {
        Root = insertNode(Root, i);
    }

    cout << "--Exercise 1--\n";
    cout << "Pre-order: "; NLR(Root); cout << '\n';
    cout << "In-order: "; LNR(Root); cout << '\n';
    cout << "Post-order: "; LRN(Root); cout << '\n';
    // cout << "Remove 30\n"; Root = deleteNode(Root, 30);
    cout << "Level-order: "; LevelOrder(Root); cout << '\n';

    cout << "--Exercise 2--\n";
    cout << "Is" << ((isFull(Root)) ? " " : " not ") << "a full tree\n";
    cout << "Is" << ((isComplete(Root)) ? " " : " not ") << "a complete tree\n";
    cout << "Is" << ((isPerfect(Root)) ? " " : " not ") << "a perfect tree\n";
    cout << "Nodes with 2 child nodes, and the left child is a divisor of the right child, in ascending order:\n";
    printSpecialNodes(Root);
    while (Root)
        Root = deleteNode(Root, Root->key);
    return 0;
}