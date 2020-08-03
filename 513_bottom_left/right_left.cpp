#include <vector>
#include <queue>

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
    int findBottomLeftValue(TreeNode *root)
    {
        std::queue<TreeNode *> node_queue;
        TreeNode *cur;
        node_queue.push(root);
        while (!node_queue.empty())
        {
            cur = node_queue.front();
            if (cur->right)
                node_queue.push(cur->right);
            if (cur->left)
                node_queue.push(cur->left);
            node_queue.pop();
        }
        return cur->val;
    }
};