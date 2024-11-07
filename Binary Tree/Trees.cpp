#include <iostream>
using namespace std;

/* implement a binary tree the same as a linkedList implemented but with
each node has 2 pointers Left and Right for at most 2 children (nodes)
similar to what a linkedList should look like

//* Head is a pointer that points to the root node and a Tail is a pointer that points to the leaf node.
+ design their atributes (//!follow linked style)
*/

struct Node
{
  int data;
  Node *Left;
  Node *right;
  Node(int value)
  {
    this->data = value;
    this->Left = nullptr;
    this->right = nullptr;
  }
};

class BinaryTrees
{
public:
  Node *Head;   // to root
  Node *Tail;   // to most recent leaf
  BinaryTrees() // constructor initialization
  {
    Head = nullptr;
    Tail = nullptr;
  }

  // insert a node, left < node < right acc to BST
  void insert(int value)
  {
    Head = insertRecursive(Head, value);
  }

  Node *insertRecursive(Node *node, int value)
  {
    // needs a base case here
    if (node == nullptr)
    {
      Node *newNode = new Node(value); // create a new node
      this->Tail = newNode;
      return newNode;
    }
    //! recursive cases
    if (value < node->data)
    {
      node->Left = insertRecursive(node->Left, value);
    }
    else if (value >= node->data)
    {
      node->right = insertRecursive(node->right, value);
    }
    return node;
  }

  void deleteTree(Node *node)
  {
    if (node == nullptr)
    {
      return;
    }
    else
    {
      deleteTree(node->Left);  // recursivley delete entire left subtree
      deleteTree(node->right); // recursivley delete entire right subtree
      delete node;             // then it deletes current node
    }
  }

  ~BinaryTrees()
  {
    deleteTree(Head); //* clean up all nodes starting from the root node
  }
};

int main()
{
  BinaryTrees myTree;
  myTree.insert(23);
  return 0;
}
