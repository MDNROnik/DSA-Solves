class Solution {
public:
    
    void fun( vector<vector<int>>& ans, vector<int>& nums, int index, int siz, vector<int>now){
        if(index==siz){
            sort(now.begin(),now.end());
            ans.push_back(now);
            return ;
        }
        now.push_back(nums[index]);
        fun(ans, nums, index+1, siz, now);
        now.pop_back();
        fun(ans, nums, index+1, siz, now);
        
        return ;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>now;
        int n= nums.size();
        fun(ans, nums, 0, n, now);
        set<vector<int>> s (ans.begin(),ans.end());
        ans .assign  (s.begin(),s.end());
        return ans;
    }
};