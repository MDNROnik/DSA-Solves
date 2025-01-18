class Solution {
public:
    int fun(vector<int>& nums, vector<vector<int>> &v, int i, int prev,int &n, int mode){
        
        if(i==n){
            return 0;
        }

        if(v[i][prev+1]!=-1){
            return v[i][prev+1];
        }

        int allow=0, not_allow=0;
        not_allow = fun(nums, v, i+1, prev, n, 1); 
        if(prev==-1 ||nums[prev]<nums[i]){

            allow =1 + fun(nums, v, i+1, i, n, 2); 
        }
        
        return v[i][prev+1] = max(allow, not_allow);
    }
    int lengthOfLIS(vector<int>& nums) {
        int prev= -1;
        int n=nums.size();
        vector<vector<int>>v(n+10, vector<int>(n+10, -1));
        return fun(nums, v, 0, prev, n,0);
    }
};