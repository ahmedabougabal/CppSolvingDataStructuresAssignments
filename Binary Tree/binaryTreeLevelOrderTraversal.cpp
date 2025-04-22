#include <iostream>
#include <vector>
#include <queue>
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

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> allLevels;
        queue<TreeNode *> q;
        if (!root)
        {
            return allLevels;
        }
        q.push(root);

        // while still having the addresses of the TreeNode pointers
        while (!q.empty())
        {
            int levelSize = q.size();
            vector<int> currentLevel;
            for (int i = 0; i < levelSize; ++i)
            {
                TreeNode *node = q.front();
                currentLevel.push_back(node->val);
                q.pop(); //* pop the node address we have read
                if (node->left)
                {
                    q.push(node->left);
                }
                if (node->right)
                {
                    q.push(node->right);
                }
            }
            allLevels.push_back(currentLevel);
        }
        return allLevels;
    }
};

/*
*********** easy to go explanation for my reference later and
remembering how i have had implemented it ,

my issues to remember : runtime (segmentation fault), when i
tried to access a value of a derefrenced pointer because of a
wrong if node == nullptr condition

got memory limit excceeded when i made a typo in an if condition
inside the for loop when enqueuing
both node's children into the queue.


Tree: 1
     / \
    2  3

* queue holds one address: &1
* pop &1 → node points to the “1” house
* read node->val (1)
* its left pointer is &2, right pointer is &3 → enqueue both
* finished first floor → result [1]
* queue now [&2, &3]
* next floor size = 2
* pop &2, read mailbox 2, enqueue nothing (both children are nullptr)
* pop &3, read mailbox 3, enqueue nothing
* queue empty → done → result [[1],[2,3]]

*/