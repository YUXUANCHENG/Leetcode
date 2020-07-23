#include <algorithm>

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
    int &diameterOfBinaryTree(TreeNode *&root)
    {
        depth(root);
        return max_path;
    }

    int depth(TreeNode *&root)
    {   
        if (!root) return 0;
        int && depth_l = depth(root->left);
        int && depth_r = depth(root->right);
        max_path = std::max(max_path, depth_l + depth_r);
        return std::max(depth_l, depth_r)+1;
    }

private:
    int max_path = 0;
};