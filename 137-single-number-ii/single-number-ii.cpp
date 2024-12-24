class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int temp=0;
        for(int i=0;i<nums.size();){
            if(i+1 == nums.size()){
                temp=nums[i];break;
            }
            else if(i+2<nums.size() &&  nums[i]!=nums[i+1] && nums[i]!=nums[i+2] ){
                temp=nums[i];break;
            }
            else{
                i+=2;i++;
            }
        }
        return temp;
    }
};