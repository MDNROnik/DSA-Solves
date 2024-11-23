class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        nums.push_back(1000000);
        int ans=0,temp=1;
        int pre=nums[0]-1;
        for(int i=1;i<nums.size();){
            pre=nums[i-1];
            while( abs(nums[i-1]-nums[i]) <=1 ){
                i++;
            }
            ans = max(ans, (abs(pre-nums[i-1])+1) );
            i++;
        }
        return ans;
    }
};