#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        unordered_map<char, int> map1;
        for (char &c : s)
        {
            map1[c]++;
        }
        for (auto pair = map1.begin(); pair != map1.end(); pair++)
        {
            ans += ((pair->second)/2) * 2;
        }
        if (ans < s.size())
            ans ++;
        return ans;
    }
};