#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode * getIntersectionNode(ListNode * & headA, ListNode * & headB) {
        ListNode* pointer_A = headA;
        ListNode* pointer_B = headB;
        while(pointer_A != pointer_B){
            pointer_A = (pointer_A != NULL) ? pointer_A->next : headB;
            pointer_B = (pointer_B != NULL) ? pointer_B->next : headA;
        }
        return pointer_A;
    }
};