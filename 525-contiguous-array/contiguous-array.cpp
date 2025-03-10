class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int ans = 0;
        map<int, pair<int,int> >mp;  
        int n = nums.size();
        int now = 0, zero=0, one=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){now++;zero++;}
            else{now--;one++;}
            if(now==0){
                ans = max(ans, (i+1));
            }
            pair<int,int>p=mp[now];
            if(p.first==0){
                p.first = i+1;
            }
            else{
                p.second = i+1;
                ans = max(ans, (p.second-p.first));
            }
            mp[now]=p;
        }
        if(zero==one){
            ans = max(ans, (zero+one));
        }
        return ans;
    }
};