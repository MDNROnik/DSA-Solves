class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i-1]==nums[i]){continue;}
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    for(int l=k+1;l<n;l++){
                        long long now = (long long)nums[i]+nums[j]+nums[k]+nums[l];
                        if( now == target){
                            ans.insert({nums[i], nums[j], nums[k], nums[l]});
                        }
                    }
                }
            }
        }
        vector<vector<int>> a (ans.begin(), ans.end());
        return a;
    }
};