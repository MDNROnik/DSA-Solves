class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int maxi = 0;
        map<int,int>v;
        for(int i=0;i<n;i++){
            v[nums[i]]++;
            if(v[nums[i]]>maxi){
                maxi = v[nums[i]];
                ans = nums[i];
            }
        }
        return ans;
    }
};