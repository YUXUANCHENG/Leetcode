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
    std::vector<double> &averageOfLevels(TreeNode *&root)
    {
        std::queue<TreeNode *> node_queue;
        node_queue.push(root);
        TreeNode *current = nullptr;
        while (!node_queue.empty())
        {
            unsigned num = node_queue.size();
            double average = 0;
            for (unsigned i = 0; i < num; i++)
            {
                current = node_queue.front();
                average += current->val;
                if (current->left)
                    node_queue.push(current->left);
                if (current->right)
                    node_queue.push(current->right);
                node_queue.pop();
            }
            result.push_back(average / num);
        }

        return result;
    }

    std::vector<double> result;
};