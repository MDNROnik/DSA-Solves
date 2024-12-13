class Solution {
public:
    void bs(vector<int>& nums, int l, int r, int &ans){
        cout<<l<<" "<<r<<endl;
        if(l>r){
            return;
        }
        if(l==r){
            ans = min(ans,min(nums[l],nums[r]));
            return;
        }
        ans = min(ans,min(nums[l],nums[r]));
        int mid = l+(r-l)/2;
        cout<<ans<<endl;
        if(ans >= nums[l] || ans > nums[mid]){

            bs(nums,l,mid,ans);
        }
        if(ans > nums[mid+1] || ans >= nums[r]){
            bs(nums,mid+1,r,ans);
        }
        return ;
    }
    int findMin(vector<int>& nums) {
        int n=nums.size();
        n-=1;
        int ans = INT_MAX;
        bs(nums,0,n,ans);
        return ans;
    }
};