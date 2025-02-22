class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        vector<int>v;
        v.push_back(0);
        int n = nums.size();
        for(int i=0;i<n;i++){
            v.push_back(v[i]+nums[i]);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            for(int j = i;j<=n;j++){
                // cout<<i<<" "<<j<<endl;
                if(v[j]-v[i-1]==k){ans++;}
                else if(v[j]-v[i-1]>k){
                    // break;
                }
            }
        }
        return ans;
    }
};