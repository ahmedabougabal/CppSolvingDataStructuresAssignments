#include <iostream>
#include <vector>
using namespace std;
/*
represent a binary tree using an array
*/

struct Node
{
  int data;
  Node *left;
  Node *right;
  Node(int data, Node *left_ptr, Node *right_ptr)
  {
    this->left = left_ptr;
    this->right = right_ptr;
    this->data = data;
  }
};

class BinaryTree
{
private:
  vector<int> arr;

public:
  void treeToArray(Node *root)
  {
    if (root == nullptr)
    {
      return;
    }
    // initilaize array with -1 to represent null nodes
    arr.resize(20, -1);
    convertToArray(root, 0);
  }
  void convertToArray(Node *root, int index)
  {
    if (root == nullptr || index >= arr.size())
    {
      return;
    }
    arr[index] = root->data;
    convertToArray(root->left, 2 * index + 1);  // left child
    convertToArray(root->right, 2 * index + 2); // right child
  }

  void printArray()
  {
    for (int i = 0; i < arr.size(); ++i)
    {
      if (arr[i] != -1)
      {
        cout << arr[i] << "\n";
      }
      else
      {
        cout << "null";
      }
    }
    cout << endl;
  }
};

int main()
{
  Node *root = new Node(1, new Node(2, new Node(4, nullptr, nullptr), new Node(5, nullptr, nullptr)),
                        new Node(3, nullptr, nullptr));
  BinaryTree bt;
  bt.treeToArray(root);
  bt.printArray();

  return 0;
}