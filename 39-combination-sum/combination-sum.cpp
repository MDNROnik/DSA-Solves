class Solution {
public:
    
    void fun( vector<vector<int>>& ans, vector<int>& nums, int index, int siz, vector<int>now, int sum, int &target){
        if(index==siz ){
            if(target==sum){
                ans.push_back(now);
            }
            return ;
        }
        fun(ans, nums, index+1, siz, now, sum, target);
        if(sum+nums[index] <= target){
            sum+=nums[index];
            now.push_back(nums[index]);
            fun(ans, nums, index, siz, now, sum, target);
        }
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>now;
        int n= nums.size();
        int sum=0;
        fun(ans, nums, 0, n, now, sum, target);
        return ans;
    }
};