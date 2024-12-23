class Solution {
public:
    void fun( vector<vector<int>>& ans, vector<int>& nums, int index, int siz, vector<int>now){
        if(index==siz){
            ans.push_back(now);
            return ;
        }
        fun(ans, nums, index+1, siz, now);
        now.push_back(nums[index]);
        fun(ans, nums, index+1, siz, now);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>now;
        int n= nums.size();
        fun(ans, nums, 0, n, now);
        return ans;
    }
};