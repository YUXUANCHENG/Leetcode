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

class Solution {
public:
    std::vector<int> & preorderTraversal(TreeNode* & root) {
        _traversal(root);
        return result;
    }

    void _traversal(TreeNode* & root){
        if (!root) return;
        result.push_back(root->val);
        _traversal(root->left);
        _traversal(root->right);
    }

    std::vector<int> result;
};