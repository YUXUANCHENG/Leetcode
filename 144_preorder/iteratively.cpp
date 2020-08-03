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

class Solution {
public:
    std::vector<int> & preorderTraversal(TreeNode* & root) {
        if (!root) return result;
        std::stack<TreeNode *> node_stack;
        node_stack.push(root);
        TreeNode * cur;
        while(!node_stack.empty()){
            cur = node_stack.top();
            node_stack.pop();
            result.push_back(cur->val);
            if (cur->right) node_stack.push(cur->right);
            if (cur->left) node_stack.push(cur->left);
        }
        return result;
    }
    std::vector<int> result;
};