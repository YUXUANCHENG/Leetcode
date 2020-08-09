#include <vector>

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
    TreeNode *sortedArrayToBST(const std::vector<int> &nums)
    {
        TreeNode *root = sortedArrayToBST(nums, 0, nums.size() - 1);
        return root;
    }
    TreeNode *sortedArrayToBST(const std::vector<int> &nums, int start, int end)
    {
        if (end < start)
            return nullptr;
        int mid = (end + start)/2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid - 1);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        return root;
    }
};