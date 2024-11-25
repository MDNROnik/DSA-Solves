class Solution {
public:
    int characterReplacement(string nums, int k) {
        int ans=0;
        int l=0,r=0;
        map<char,int>mp;
        int n=nums.size();
        int maxi=0;
        while(r<n){
            mp[nums[r]]++;
            maxi = max(maxi, mp[nums[r]]);
            if( ( ( (r-l) + 1) - maxi ) > k ){
                mp[nums[l]]--;
                l++;
            }
            ans =  max (ans, ( (r-l) + 1));
            r++;
        }
        return ans;
    }
};