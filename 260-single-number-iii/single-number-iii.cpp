class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            num^=nums[i];
        }
        vector<int>v;
        for(int i=0;i<n;i++){
            int now = num^nums[i];
            int c=0, first = 0;
            for(int j=0;j<n;j++){
                if(now==nums[j]){
                    c++;first=j;
                }
            }
            if(c>1){
            }
            else if(c>0){
                v.push_back(nums[first]);
                v.push_back(nums[i]);
                break;
            }
        }
        return v;
    }
};