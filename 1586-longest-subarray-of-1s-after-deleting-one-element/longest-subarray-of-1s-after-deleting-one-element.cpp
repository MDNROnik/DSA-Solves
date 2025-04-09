class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        map<int,pair<int,int>>mp;
        int n=nums.size();
        int count=0, zero=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                mp[i].first = count;
                count=0;
                zero++;
            }
            else{
                count++;
            }
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                mp[i].second = count;
                count=0;
                zero++;
            }
            else{
                count++;
            }
        }
        if(zero==0){
            return n-1;
        }
        int ans = 0;
        for(auto a=mp.begin(); a!=mp.end(); a++){
            // cout<<a->first<<" "<<a->second.first<<" "<<a->second.second<<endl;
            ans = max(ans, ( a->second.first + a->second.second ) );
        }
        
        return ans;
    }
};