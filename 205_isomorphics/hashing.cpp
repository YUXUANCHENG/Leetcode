#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        for (int i = 0; i < s.size(); i++)
        {
            auto find_result1 = map1.find(s[i]);
            auto find_result2 = map2.find(t[i]);
            if (find_result1 != map1.end() && find_result2 != map2.end())
            {
                if (find_result1->second != find_result2->second)
                    return false;
            }
            else if(find_result1 == map1.end() && find_result2 == map2.end())
            {         
                map1[s[i]] = i;
                map2[t[i]] = i;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};