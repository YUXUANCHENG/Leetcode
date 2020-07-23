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
    ListNode *reverseList(ListNode * head)
    {
        if (!head) return nullptr;
        while(head)
        {
            pointer_stack.push(head);
            head = head->next;
        }
        ListNode * new_head = pointer_stack.top();
        head = new_head;
        pointer_stack.pop();
        while(!pointer_stack.empty())
        {
            head->next = pointer_stack.top();
            pointer_stack.pop();
            head = head->next;
        }
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
    std::stack<ListNode *> pointer_stack;
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

    solution.print(&one);
    ListNode * newhead = solution.reverseList(&one);
    solution.print(newhead);

    return 0;
}