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
    TreeNode *convertBST(TreeNode *&root)
    {
        __traverse(root);
        return root;
    }
    void __traverse(TreeNode *&root)
    {
        if(!root) return;
        __traverse(root->right);
        sum += root->val;
        root->val = sum;
        __traverse(root->left);
    }
    int sum = 0;
};