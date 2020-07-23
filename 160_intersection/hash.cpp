#include <iostream>
#include <unordered_set>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * getIntersectionNode(ListNode * & headA, ListNode * & headB) {
        std::unordered_set<ListNode *> node_set;
        ListNode* pointer_A = headA;
        ListNode* pointer_B = headB;
        while(pointer_A != NULL){
            node_set.emplace(pointer_A);
            pointer_A = pointer_A->next;
        }
        while(pointer_B != NULL){
            if (node_set.find(pointer_B)!= node_set.end())
                return pointer_B;
            else
                pointer_B = pointer_B->next;
        }
        return pointer_B;
    }
};