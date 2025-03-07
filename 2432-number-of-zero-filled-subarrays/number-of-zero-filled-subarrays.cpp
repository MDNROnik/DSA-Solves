#define ll long long
class Solution {
public:
    ll zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0;
        int n=nums.size();
        for(int i=0;i<n;){
            if(nums[i]==0){
                ll count = 0;
                while(i<n){
                    if(nums[i]==0){
                        count++;
                    }
                    else{
                        break;
                    }
                    i++;
                }
                count*=(count+1);
                count/=2;
                ans+=count;
            }
            else{
                i++;
            }
        } 
        return ans;
    }
};