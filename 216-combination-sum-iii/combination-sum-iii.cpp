class Solution {
public:
    
    void fun( vector<vector<int>>& ans, vector<int>& nums, int index, int siz, vector<int>now, int sum, int &target, int &msiz){
        if(index==siz ){
            if(target==sum && now.size()==msiz){
                ans.push_back(now);
            }
            return ;
        }
        fun(ans, nums, index+1, siz, now, sum, target, msiz);
        if(sum+nums[index] <= target && now.size()<msiz){
            sum+=nums[index];
            now.push_back(nums[index]);
            fun(ans, nums, index+1, siz, now, sum, target, msiz);
        }
        return ;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>now;
        vector<int>nums;
        for(int i=1;i<=9;i++){nums.push_back(i);}
        
        int sum=0;
        fun(ans, nums, 0, 9, now, sum, n,k);
        return ans;
    }
};
