class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        int ans, count=0;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(count<mp[nums[i]]){
                count = max(count, mp[nums[i]]);
                ans=nums[i];
            }
        }
        return ans;
    }
};