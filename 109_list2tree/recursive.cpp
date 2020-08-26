struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
    TreeNode *sortedListToBST(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return new TreeNode(head->val);
        ListNode *mid = find_mid(head);
        ListNode *second_head = mid->next->next;
        TreeNode *root = new TreeNode(mid->next->val);
        delete mid->next;
        mid->next = nullptr;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(second_head);
        return root;
    }

    ListNode *find_mid(ListNode *head)
    {
        if (!head)
            return nullptr;
        if (!head->next)
            return head;
        ListNode *mid = head;
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        return mid;
    }
};