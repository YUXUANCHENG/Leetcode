#include <vector>
#include <stack>

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
    TreeNode *convertBST(TreeNode *&root)
    {
        TreeNode *cur = root;
        std::stack<TreeNode *> node_stack;
        while (cur || !node_stack.empty())
        {
            while (cur)
            {
                node_stack.push(cur);
                cur = cur->right;
            }
            cur = node_stack.top();
            sum += cur->val;
            cur->val = sum;
            cur = cur->left;
            node_stack.pop();
        }
        return root;
    }
    int sum = 0;
};