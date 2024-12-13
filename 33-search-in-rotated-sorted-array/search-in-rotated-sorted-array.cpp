class Solution {
public:
void bs(vector<int>& nums, int l, int r, int &ans, int &index){
        cout<<l<<" "<<r<<endl;
        if(l>r){
            return;
        }
        if(l==r){
            if(ans == nums[l]){
                index = l;
            }
            return;
        }
        
        int mid = l+(r-l)/2;
        cout<<nums[l]<<" "<<nums[mid]<<" "<<ans<<endl;
        if(ans >= nums[l] || ans <= nums[mid]){
            bs(nums,l,mid,ans,index);
        }
        if(ans >= nums[mid+1] || ans <= nums[r]){
            bs(nums,mid+1,r,ans,index);
        }
        return ;
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        n-=1;
        int index =-1;
        int ans = INT_MAX;
        bs(nums,0,n,target,index);
        return index;
    }
    
};