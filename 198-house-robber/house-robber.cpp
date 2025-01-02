class Solution {
public:
    int fun( vector<int> &mp, int i, int n, vector<int> &nums ){
        if(i>=n){
            return 0;
        }
        if(mp[i]>-1){
            return mp[i];
        }
        int notpick = fun(mp, i+1, n, nums);
        int pick = nums[i] + fun(mp, i+2, n, nums);

        return mp[i] = max(notpick, pick);
    }
    int rob(vector<int>& nums) {
        
        int n=nums.size();
        vector<int>mp(n,-1);
        return fun(mp, 0, n, nums);
    }
};