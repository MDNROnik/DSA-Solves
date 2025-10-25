class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dict = {}
        lenth = len(nums)

        for index in range(0, lenth):
            if nums[index] not in dict:
                dict[nums[index]] = 0
            dict[nums[index]] = dict[nums[index]] + 1
        
        list = []
        for key, value in dict.items():
            list.append([value, key])

        list.sort(reverse=True)
        ans = []

        for index in range (0, k):
            ans.append(list[index][1])

        return ans
        