#include <iostream>
using namespace std;

class Node
{
private:
  int data;

public:
  Node *left;
  Node *right;
  Node *root = nullptr;
  void set_data(int data)
  {
    this->data = data;
  }
  int get_data()
  {
    return this->data;
  }
  Node(int myData)
  {
    this->data = myData;
    this->left = nullptr;
    this->right = nullptr;
  }
};

int evaluateTree(Node *curr)
{
  if (curr == nullptr)
  {
    return 0;
  }
  if (curr->left == nullptr && curr->right == nullptr)
  {
    return curr->get_data();
  }
  int left = evaluateTree(curr->left);
  int right = evaluateTree(curr->right);
  switch (curr->get_data())
  {
  case '+':
    return left + right;

  case '-':
    return left - right;

  case '*':
    return left * right;

  case '/':
    return left / right;

  default:
    throw invalid_argument("Invalid operator");
  }
  return 0;
}

int main()
{
  Node *root = new Node('*');
  Node *plus = new Node('+');
  Node *subtract = new Node('-');
  Node *divide = new Node('/');

  Node *node2 = new Node(2);
  Node *node3 = new Node(3);

  Node *node9 = new Node(9);
  Node *node8 = new Node(8);
  Node *node4 = new Node(4);

  root->left = plus;
  plus->left = node2;
  plus->right = node3;

  root->right = subtract;
  subtract->right = divide;
  subtract->left = node9;
  divide->right = node4;
  divide->left = node8;

  cout << evaluateTree(root) << "\n";

  return 0;
}
