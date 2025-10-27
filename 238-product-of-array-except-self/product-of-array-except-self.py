class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        s = len(nums)
        preList = [1]*(s+1)
        sufList = [1]*(s+1)
        answer = [0]*s

        for i in range(0, s):
            preList[i+1] = preList[i]*nums[i]

            sufList[s-(i+1)] = sufList[s-(i)] * nums[s-(i+1)]

        # print(preList)
        # print(sufList)

        for i in range(0, s):
            answer[i] = preList[i]*sufList[i+1]

        return answer