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
//Exercise 1
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

//Exercise 2
int height(Node* root) {
    if (!root) return 0;
    int hleft = height(root->left);
    int hright = height(root->right);
    return 1 + ((hleft > hright) ? hleft : hright);
}
int countNode(Node* root) {
    if (!root) return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}
int sumNode(Node* root) {
    if (!root) return 0;
    return root->key + sumNode(root->left) + sumNode(root->right);
}
int countLeaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    return countLeaf(root->left) + countLeaf(root->right);
}
int countLess(Node* root, int x) {
    if (!root) return 0;
    if (root->key < x) return 1 + countLess(root->left, x) + countLess(root->right, x);
    else return countLess(root->right, x) + countLess(root->left, x);
}
int countGreater(Node* root, int x) {
    if (!root) return 0;
    if (root->key > x) return 1 + countLess(root->left, x) + countLess(root->right, x);
    else return countLess(root->right, x) + countLess(root->left, x);
}

int main()
{
    vector<int> a = {8, 6, 5, 7, 10, 9};
    Node* Root = NULL;
    for(int i : a)
    {
        Root = insert(Root, i);
    }
    //Exercise 1
    cout << "Pre-order: "; NLR(Root); cout << '\n';
    cout << "In-order: "; LNR(Root); cout << '\n';
    cout << "Post-order: "; LRN(Root); cout << '\n';
    cout << "Remove 8\n";
    deleteNode(Root, 8);
    cout << "Level-order: "; LevelOrder(Root); cout << '\n';

    //Exercise 2
    int x = 7;
    cout << "Height of BST: " << height(Root) << '\n';
    cout << "Number of node of BST: " << countNode(Root) << '\n';
    cout << "Total value of all node of BST: " << sumNode(Root) << '\n';
    cout << "Number of leaves of BST: " << countLeaf(Root) << '\n';
    cout << "Number of nodes of BST which key value is less than 7: " << countLess(Root, 7) << '\n';
    cout << "Number of nodes of BST which key value is greater than 7: " << countGreater(Root, 7) << '\n';
    // clear tree
    while (Root) {
        Root = deleteNode(Root, Root->key);
    }
    return 0;
}