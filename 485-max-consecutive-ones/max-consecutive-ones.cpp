class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        nums.push_back(0);
        int ans=0;
        for(int i=0;i<nums.size();){
            if(nums[i]==1){
                int temp=0;
                while(nums[i]==1){
                    temp++;
                    i++;
                }
                ans=max(ans,temp);
            }
            else{
                i++;
            }
        }
        return ans;
    }
};