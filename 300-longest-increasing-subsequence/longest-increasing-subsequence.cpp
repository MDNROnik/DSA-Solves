#define ll long long
class Solution {
public:
    int fun(vector<int>& nums , vector<vector<int>>& dp, int pre, int now){
        if(now==nums.size()){return 0;}
        if(dp[now][pre+1] != -1){
            return dp[now][pre+1] ;
        }
        int not_pick = fun(nums,dp,pre,now+1);
        int pick = 0;
        if(pre==-1 || nums[pre]<nums[now]){
            pick = 1 + fun(nums,dp,now,now+1);
        }
        return dp[now][pre+1] = max(not_pick,pick);
    }
    int lengthOfLIS(vector<int>& nums) {
       int n = nums.size();
       vector<vector<int>> dp(n+1, vector<int>(n + 1, -1));
       return fun(nums,dp,-1,0);
    }
};