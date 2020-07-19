#include <unordered_map>
#include <vector>
#include <iostream>

class Solution{
    public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int,int> hash_table;
        std::vector<int> result;
        for (int index = 0; index < nums.size(); index ++){
            int complement = target - nums.at(index);
            auto find_result = hash_table.find(complement);
            if (find_result != hash_table.end())
            {
                if (find_result->second != index){
                    result.push_back(index);
                    result.push_back(find_result->second);
                    return result;
                }
            }
            else
            {
                hash_table.emplace(nums.at(index), index);
            }
            
        }
        return result;
    }
};

int main(){
    Solution solution;
    std::vector<int> list_test = {3,2,4};
    std::vector<int> result = solution.twoSum(list_test, 6);
    std::cout << result.at(0) << " " << result.at(1);
    return 0;
}
