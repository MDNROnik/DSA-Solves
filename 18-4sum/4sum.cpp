class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>>ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                int l = j+1, r = n-1;
                while(l<r){
                    if((long long)nums[i]+nums[j]+nums[l]+nums[r] == target){
                        vector<int>v;
                        v.push_back(nums[i]);
                        v.push_back(nums[j]);
                        v.push_back(nums[l]);
                        v.push_back(nums[r]);
                        ans.insert(v);
                        l++;r--;
                    }
                    else if((long long)nums[i]+nums[j]+nums[l]+nums[r] > target){
                        r--;
                    }
                    else{
                        l++;
                    }
                }
            }
        }
        vector<vector<int>> a (ans.begin(), ans.end());
        return a;
    }
};