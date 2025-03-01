class Solution {
public:
    bool fun(vector<int>& nums, int i, int &n, int count){
        // if(i==n){
        //     return true;
        // }
        if(i+1<n){
            if(nums[i]<=nums[i+1]){
                return fun(nums, i+1, n, count);
            }
            else{
                if(count==1){
                    return false;
                }
                if( (i-1>=0 && nums[i-1]<=nums[i+1]) || i==0){
                    int temp = nums[i];
                    nums[i]=nums[i+1];
                    bool now = fun(nums, i+1, n, count+1);
                    if(now==true){
                        return true;
                    }
                    nums[i]=temp;
                }
                nums[i+1]=nums[i];
                return fun(nums, i+1, n, count+1);
            }
        }
        else{
            return true;
        }
    }
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();
        return fun(nums, 0, n, 0);
    }
};