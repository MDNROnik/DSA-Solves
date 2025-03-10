class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        map<int, int >mp;  
        int n = nums.size();
        int now = 0, zero=0, one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){now++;zero++;}
            else{now--;one++;}
            if(now==0){
                ans = max(ans, (i+1));
            }
            if(mp[now]==0){
                mp[now] = i+1;
            }
            else{
                ans = max(ans, (i+1-mp[now]));
            }
        }
        if(zero==one){
            ans = max(ans, (zero+one));
        }
        return ans;
    }
};