#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * current_A = headA;
        while(current_A != NULL){
            ListNode * current_B = headB;
            while(current_B!= NULL){
                if (current_A==current_B){
                        return current_B;
                }
                else{
                    current_B = current_B->next;
                }
            }
            current_A = current_A->next;
        }
        return current_A;
    }

};