class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashtable = {}
        for index, value in enumerate(nums):
            complement = target - value 
            if complement in hashtable:
                return index,hashtable[complement]
            else:
                hashtable[value] = index

solution = Solution()          
print(solution.twoSum([2,7,11,15],9))