class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int now = 1, n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i< n;i++){
            if(nums[i]==now){
                now++;
            }
        }
        return now;
    }
};