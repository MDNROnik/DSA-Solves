class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                int j=i+1;
                while(j<nums.size()){
                    if(nums[j]!=0){
                        nums[i]=nums[j];nums[j]=0;break;
                    }
                    j++;
                }
            }
        }
    }
};