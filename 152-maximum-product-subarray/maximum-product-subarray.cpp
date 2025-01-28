class Solution {
public:
    pair<int,int> fun(vector< pair<int,int> >&mp, vector<int>&nums, int i, int &n){
        if(i>=n){
            return {1,1};
        }
        if(mp[i].first!=INT_MAX){
            return mp[i];
        }
        pair<int,int> now = fun(mp, nums, i+1, n);
        int m = now.first;
        int m2 = now.second;
        int maxi = now.first*nums[i];
        int mini = now.second*nums[i];
   
        int first = max(maxi, max(nums[i], mini));
        int second = min(maxi, min(nums[i], mini));

        // cout<<nums[i]<<" "<<first<<" "<<second<<endl;
        return mp[i] = {first, second};
    }
    int maxProduct(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector< pair<int,int> >mp(n+10, {INT_MAX, INT_MAX});
        int ans = INT_MIN;
        for(int i=0;i<n;i++){
            pair<int,int> p = fun(mp, nums, i, n);
            ans = max(ans, max(p.first, p.second));
        }
        return ans;
    }
};