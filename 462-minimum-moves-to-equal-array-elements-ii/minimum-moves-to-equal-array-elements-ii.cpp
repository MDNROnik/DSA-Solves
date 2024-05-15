class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long  maxi=LLONG_MAX;
        int n=nums.size();
        for(int i=0;i<n;i++){
            long long  total=0;
            for(int j=0;j<n;j++){
                total+=abs(nums[i]-nums[j]);
            }
            maxi=min(maxi,total);
        }
        return maxi;
    }
};