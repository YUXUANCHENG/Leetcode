#include <vector>
#include <unordered_map>
#include <math.h>

class Solution {
public:
    int findLHS(std::vector<int>& nums) {
        int result = 0;
        std::unordered_map<int, int> map;
        for (int num : nums)
        {
            auto find_result = map.find(num);
            if (find_result == map.end())
                map.emplace(num,1);
            else 
                find_result->second ++;
        }
        for (auto iterat = map.begin(); iterat != map.end(); iterat ++)
        {
            auto find_result = map.find(iterat->first + 1);
            if (find_result != map.end())
                {
                    int temp = iterat -> second + find_result -> second;
                    result = std::max(result, temp);
                }
        }
        return result;
    }
};