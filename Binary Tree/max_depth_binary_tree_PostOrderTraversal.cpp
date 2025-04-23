#include <iostream>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int postOrderTraversal(TreeNode *node)
    {
        int depth1 = 0;
        int depth2 = 0;

        if (node == nullptr)
        {
            return 0;
        }
        if (node->left)
        {
            depth1 = postOrderTraversal(node->left);
        }
        if (node->right)
        {
            depth2 = postOrderTraversal(node->right);
        }
        return 1 + max(depth1, depth2); // adding 1 to count from the current node i am at which is the root node
    }

    int maxDepth(TreeNode *root)
    {
        return postOrderTraversal(root);
    }
};