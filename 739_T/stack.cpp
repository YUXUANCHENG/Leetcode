#include <stack>
#include <vector>

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &T)
    {
        std::stack<int> s1;
        int size = T.size() - 1;
        std::vector<int> ans(size + 1, 0);
        while (size >= 0)
        {
            while (!s1.empty() && T.at(size) >= T.at(s1.top()))
            {
                s1.pop();
            }
            ans.at(size) = !s1.empty() ? s1.top() - size : 0;
            s1.push(size);
            size--;
        }
        return ans;
    }
};