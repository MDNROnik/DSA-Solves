class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0]>target){
            return 0;
        }
        else if(nums[nums.size()-1]<target){
            return nums.size();
        }
        int ans;
        int i=0, j=nums.size()-1;
        while(i<=j){
            int mid=i+j;
            mid/=2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return i;

    }
};