class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        vector<int>repeat, missing, ans;
        for(int i=1;i<=n;i++){
            if(mp[i] > 1){
                repeat.push_back(i);
            }
            else if(mp[i]==0){
                missing.push_back(i);
            }
        }
        ans.insert(ans.end(), repeat.begin(), repeat.end());
        ans.insert(ans.end(), missing.begin(), missing.end());
        return ans;
    }
};