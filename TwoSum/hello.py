class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for index_i, i in enumerate(nums):
            for index_j, j in enumerate(nums):
                if (i + j == target) and (index_i != index_j):
                    return index_i, index_j

solution = Solution()          
solution.twoSum([2,7,11,15],9)
