#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalanced(TreeNode* & root) {
        return dfs(root) != -1;
    }
    int dfs(TreeNode* & root){
        if (root){
            int && depth_l = dfs(root->left);
            int && depth_r = dfs(root->right);
            if (depth_l == -1 || depth_r == -1 || std::abs(depth_l-depth_r) > 1)
                return -1;
            else 
                return std::max(depth_l, depth_r)+1;
        }
        else
            return 0;
    }
};