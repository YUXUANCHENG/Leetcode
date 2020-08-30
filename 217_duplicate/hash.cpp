#include <vector>
#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        bool result = false;
        std::unordered_set<int> set;
        for (int num : nums)
        {
            auto find_result = set.find(num);
            if (find_result == set.end())
                set.insert(num);
            else
            {
                result = true;
                break;
            }
        }
        return result;
    }
};