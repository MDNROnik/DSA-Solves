class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" "<<i+1<<endl;
            if(nums[i]==i){
                continue;
            }
            return i;
        }
        return nums.size();
    }
};