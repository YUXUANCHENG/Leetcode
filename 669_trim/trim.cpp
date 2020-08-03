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
    TreeNode *trimBST(TreeNode *root, int &L, int &R)
    {
        if (!root)
            return nullptr;
        if (root->val > R)
        {
            root = root->left;
            return trimBST(root, L, R);
        }
        if (root->val < L)
        {
            root = root->right;
            return trimBST(root, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};