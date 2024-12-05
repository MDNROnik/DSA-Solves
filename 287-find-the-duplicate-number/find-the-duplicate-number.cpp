class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(100005, 0);
        int n=nums.size(),i=0;
        for( i=0;i<n;i++){
            if(v[nums[i]]==0){
                v[nums[i]]++;
            }
            else{
                break;
            }
        }
        return nums[i];
    }
};