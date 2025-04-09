class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,pair<int,int>>mp;
        int n=nums.size();
        int count=0, count2=0, zero=0, j=n-1;
        for(int i=0;i<n;i++, j--){
            if(nums[i]==0){
                mp[i].first = count;
                count=0;
                zero++;
            }
            else{
                count++;
            }

            if(nums[j]==0){
                mp[j].second = count2;
                count2=0;
            }
            else{
                count2++;
            }
        }
        if(zero==0){
            return n-1;
        }
        int ans = 0;
        for(auto a=mp.begin(); a!=mp.end(); a++){
            ans = max(ans, ( a->second.first + a->second.second ) );
        }
        
        return ans;
    }
};