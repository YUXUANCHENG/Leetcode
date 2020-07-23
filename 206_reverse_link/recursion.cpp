#include <stack>
#include <iostream>

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
    ListNode * & reverseList(ListNode * & head)
    {
        if (!head || !head->next) return head;
        new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    void print(ListNode * head){
        while(head){
            std::cout<< head->val << " " ;
            head = head->next;
        }
        std::cout << std::endl;
    }
private:
    ListNode * new_head = nullptr;
};

int main(){
    Solution solution;
    ListNode one(1);
    ListNode two(2);
    ListNode three(3);
    ListNode four(4);
    one.next = &two;
    two.next = &three;
    three.next = &four;

    ListNode * head = &one;
    solution.print(head);
    ListNode * newhead = solution.reverseList(head);
    solution.print(newhead);

    return 0;
}