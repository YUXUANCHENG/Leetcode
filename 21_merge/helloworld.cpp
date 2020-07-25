
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {  
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode * newhead;
        if (l1->val <= l2->val){
            newhead = l1;
            l1 = l1->next;
        }
        else if (l1->val > l2->val){
            newhead = l2;
            l2 = l2->next;
        }
        ListNode * current = newhead;
        while(l1 ||l2){
            if(!l1){
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
            else if(!l2){
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            }
            else if (l1->val <= l2->val){
                current->next = l1;
                l1 = l1->next;
                current = current->next;
            }
             else if (l1->val > l2->val){
                current->next = l2;
                l2 = l2->next;
                current = current->next;
            }
        }
        return newhead;
    }
};