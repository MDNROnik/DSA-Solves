class Solution {
public:
    bool fun(vector<int>& nums, int i, int &n, int count){
        if(i+1<n){
            if(nums[i]<=nums[i+1]){
                return fun(nums, i+1, n, count);
            }
            else{
                if(count==1){
                    return false;
                }
                if( (i-1>=0 && nums[i-1]<=nums[i+1]) || i==0){
                    if(fun(nums, i+1, n, count+1)){
                        return true;
                    }
                }
                nums[i+1]=nums[i];
                return fun(nums, i+1, n, count+1);
            }
        }
        return true;
    }
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        return fun(nums, 0, n, 0);
    }
};