#include <stack>
#include <string>

using namespace std;

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int result = 0;
        stack<char> s1;
        stack<char> s2;
        for (char n : s)
        {
            if (s1.empty() && s2.empty())
                s1.push(n);
            else
            {
                if (s1.empty() && !s2.empty())
                {
                    while (!s2.empty())
                    {
                        char temp = s2.top();
                        s2.pop();
                        s1.push(temp);
                    }
                }
                if (n == s1.top() && s2.empty())
                {
                    s1.push(n);
                }
                if (n == s1.top() && !s2.empty())
                {
                    while (!s1.empty())
                        s1.pop();
                    while (!s2.empty())
                    {
                        char temp = s2.top();
                        s2.pop();
                        s1.push(temp);
                    }
                }
                if (n != s1.top())
                {
                    s1.pop();
                    result++;
                    s2.push(n);
                }
            }
        }
        return result;
    }
};

int main()
{
    Solution solution;
    solution.countBinarySubstrings("100111001");
    return 0;
}