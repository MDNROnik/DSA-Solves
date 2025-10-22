class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        dic = {}
        for index in range(0, len(nums)):
            if nums[index] not in dic:
                dic[nums[index]] = []   # create a new list
            dic[nums[index]].append(index)

        first = -1
        second = -1
        for index in range(0, len(nums)):
            remain = target-nums[index]
            if remain in dic:
                first=index
                array = dic[remain]
                for i in range(0, len(array)):
                    if (index != array[i]):
                        second=array[i]
                        break
            if second != -1:
                break

        return [first, second]
        