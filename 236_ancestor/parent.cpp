#include <unordered_map>
#include <queue>
#include <unordered_set>

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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        std::unordered_map<TreeNode *, TreeNode *> parent;
        std::queue<TreeNode *> node_queue;
        node_queue.push(root);
        parent.emplace(root, nullptr);
        while (!node_queue.empty())
        {
            root = node_queue.front();
            if (root->left)
            {
                node_queue.push(root->left);
                parent.emplace(root->left, root);
            }
            if (root->right)
            {
                node_queue.push(root->right);
                parent.emplace(root->right, root);
            }
            node_queue.pop();
        }
        std::unordered_set<TreeNode *> parent_of_p;
        while (p)
        {
            parent_of_p.emplace(p);
            auto parent_p = parent.find(p);
            p = parent_p->second;
        }
        while (q && parent_of_p.find(q) == parent_of_p.end())
        {
            auto parent_q = parent.find(q);
            q = parent_q->second;
        }
        return q;
    }
};

int main(){
    Solution solution;
    TreeNode one(1);
    TreeNode two(2);
    TreeNode three(3);
    TreeNode four(4);
    one.left = &two;
    two.right = &three;
    one.right = &four;

    TreeNode * head = &one;
    TreeNode * newhead = solution.lowestCommonAncestor(head, &two, &four);

    return 0;
}