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
    Node *temp = newroot->left;
    newroot->left = root;
    root->right = temp;
    newroot->height = 1 + max(height(newroot->right), height(newroot->left));
    root->height = 1 + max(height(root->right), height(root->left));
    return newroot;
}
Node *RRotate(Node *root)
{
    Node *newroot = root->left;
    Node *temp = newroot->right;
    newroot->right = root;
    root->left = temp;
    newroot->height = 1 + max(height(newroot->right), height(newroot->left));
    root->height = 1 + max(height(root->right), height(root->left));
    return newroot;
}
Node *insertNode(Node *root, int data)
{
    if (!root)
        return newNode(data);
    if (root->key == data)
        return root;
    if (root->key > data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);
    root->height = 1 + max(height(root->right), height(root->left));
    // int bf = balance(root);
    // if (bf > 1 && balance(root->left) > 0) // LL
    //     return RRotate(root);
    // if (bf > 1 && balance(root->left) < 0) // LR
    // {
    //     root->left = LRotate(root->left);
    //     return RRotate(root);
    // }
    // if (bf < 1 && balance(root->right) < 0) // RR
    //     return LRotate(root);
    // if (bf < 1 && balance(root->right) > 0) // RL
    // {
    //     root->right = RRotate(root->right);
    //     return LRotate(root);
    // }
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
    // if (root == NULL)
    //     return root;
    // int bf = balance(root);
    // if (root == NULL)
    //     return root;
    // int bf = balance(root);
    // if (bf > 1 && balance(root->left) >= 0)
    //     return RRotate(root);
    // if (bf > 1 && balance(root->left) < 0) // LR
    // {
    //     root->left = LRotate(root->left);
    //     return RRotate(root);
    // }
    // if (bf < 1 && balance(root->right) <= 0) // RR
    //     return LRotate(root);
    // if (bf < 1 && balance(root->right) > 0) // RL
    // {
    //     root->right = RRotate(root->right);
    //     return LRotate(root);
    // }
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

int main()
{
    vector<int> a = {3, 2, 1, 10, 15};
    Node *Root = NULL;
    for (int i : a)
    {
        Root = insertNode(Root, i);
    }
    cout << "Pre-order: ";
    NLR(Root);
    cout << '\n';
    cout << "In-order: ";
    LNR(Root);
    cout << '\n';
    cout << "Post-order: ";
    LRN(Root);
    cout << '\n';
    cout << "Remove 1\n";
    // deleteNode(Root, 1);
    cout << "Level-order: ";
    LevelOrder(Root);
    cout << '\n';
    return 0;
}