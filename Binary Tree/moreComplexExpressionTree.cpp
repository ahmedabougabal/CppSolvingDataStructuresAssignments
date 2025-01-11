#include <iostream>
using namespace std;

class Node
{
private:
	int data;

public:
	Node *root = nullptr;
	Node *left;
	Node *right;

	void setData(int myData)
	{
		this->data = myData;
	}

	int get_data()
	{
		return this->data;
	}

	Node(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
	// adds evaluate functionality (leaf got the numbers while internal nodes got the operators)
	// recursive approach will be used
};

int evaluate(Node *current)
{
	if (current->left == nullptr && current->right == nullptr)
	{
		return current->get_data();
	}
	int leftResult = evaluate(current->left);
	int rightResult = evaluate(current->right);

	if (current->get_data() == '+')
	{
		return leftResult + rightResult;
	}
	else if (current->get_data() == '*')
	{
		return leftResult * rightResult;
	}
	return 0;
}

void printInOrder(Node *root)
{
	if (root == nullptr)
	{
		return;
	}

	printInOrder(root->left);

	if (root->get_data() == '+' || root->get_data() == '*')
	{
		cout << char(root->get_data()) << "\n";
	}
	else
	{
		cout << root->get_data() << "\n";
	}

	printInOrder(root->right);

	// cout << root->left->get_data() << "\n";
	// cout << root->get_data() << "\n";
	// cout << root->right->get_data() << "\n";
}

int main()
{
	Node *plus = new Node('+');
	Node *node2 = new Node(2);
	Node *node3 = new Node(3);
	plus->left = node2;
	plus->right = node3;

	Node *multiply = new Node('*');
	Node *node4 = new Node(4);
	multiply->left = plus;
	multiply->right = node4;

	printInOrder(multiply);
	cout << "\n=================Evaluation==================\n";
	cout << evaluate(multiply);
	return 0;
}
