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
        if (root){
            int && left_depth = depth(root->left);
            int && right_depth  = depth(root->right);
            return (std::abs(left_depth - right_depth) <= 1 && isBalanced(root->left) && isBalanced(root->right));
        }
        else
            return true;
    }
    
    int depth(TreeNode* &root){
        return root? std::max(depth(root->left), depth(root->right))+1 : 0;
    }
};