#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int value)
    {
        this->data = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// LVR (left, visit, right)

void printInOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    if (node->data == '+' || node->data == '-' || node->data == '*' || node->data == '/')
    {
        cout << char(node->data);
    }
    printInOrder(node->left);
    cout << node->data << "\n";
    printInOrder(node->right);
}

// LRV (left, right, visit)
void printPostOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    printPostOrder(node->left);
    printPostOrder(node->right);
    cout << node->data << "\n";
}

// preorder (visit, left, right) VLR
void printPreOrder(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->data << "\n";
    cout << node->left->data << "\n";
    cout << node->right->data << "\n";
}

int main()
{
    Node *plus = new Node('+'); // will print char of '+' => 43
    // what if i needed to print the actual sign + ?
    // * will add a type flag to the inorder function

    Node *node2 = new Node(2);
    Node *node3 = new Node(3);

    plus->left = node2;
    plus->right = node3;

    printInOrder(plus);
    cout << "\n============================\n";

    printPostOrder(plus);
    cout << "\n============================\n";
    printPreOrder(plus);
    return 0;
}