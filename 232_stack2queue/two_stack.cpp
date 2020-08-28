#include <stack>

class MyQueue
{
public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while(!s2.empty())
        {
            temp = s2.top();
            s2.pop();
            s1.push(temp);
        }
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int x = peek();
        s2.pop();
        return x;
    }

    /** Get the front element. */
    int peek()
    {
        while(!s1.empty())
        {
            temp = s1.top();
            s1.pop();
            s2.push(temp);
        }
        return s2.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty() && s2.empty();
    }

private:
    std::stack<int> s1;
    std::stack<int> s2;
    int temp;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */