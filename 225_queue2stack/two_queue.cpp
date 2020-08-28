#include <queue>

class MyStack
{
public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q1.push(x);
        int size = q1.size();
        while (size - 1 > 0)
        {
            temp = q1.front();
            q1.pop();
            q1.push(temp);
            size--;
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int x = q1.front();
        q1.pop();
        return x;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }

private:
    std::queue<int> q1;
    int temp;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */