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
    cout << "\n";
    return 0;
}