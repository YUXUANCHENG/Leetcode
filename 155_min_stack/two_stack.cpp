#include <stack>

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        if (min_s.empty())
            min_s.push(x);
        else
        {
            int min = getMin();
            if (x < min)
                min_s.push(x);
            else
                min_s.push(min);
        }
    }

    void pop()
    {
        int x = s.top();
        s.pop();
        min_s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return min_s.top();
    }

private:
    std::stack<int> s;
    std::stack<int> min_s;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */