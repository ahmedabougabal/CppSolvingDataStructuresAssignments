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
        int result;
        if (node == nullptr)
        {
            return 0;
        }
        depth1 = postOrderTraversal(node->left);
        depth2 = postOrderTraversal(node->right);

        if (depth1 == 0)
        {
            result = 1 + depth2;
        }

        if (depth2 == 0)
        {
            result = 1 + depth1;
        }
        if (depth1 != 0 && depth2 != 0)
        {
            result = 1 + min(depth1, depth2);
        }
        return result;
    }

    int minDepth(TreeNode *root)
    {
        return postOrderTraversal(root);
    }
};
/*
test case i struggled with  [2,null,3,null,4,null,5,null,6]

the problem asked to get the min depth from the root node to the nearest leaf node , where a leaf node as stated in the
problem's desription is the node with no children.

so [2,null,3,null,4,null,5,null,6] is a right skewed chained tree of lenght = 5

so max depth is 5 and the min depth is also 5 not 1, because 6 is the deapest leaf node :'(


how have i solved it ?

If left child is null, the minimum path must go right.
• If right child is null, the minimum path must go left.
• Otherwise (both children present), use 1 + min(depth1 , depth2).

*/