class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=0;
        //int o = n ^ m; 
        //cout<<o<<endl;
        int m = nums.size();
        for(int i=0;i<m;i++){
            n^=nums[i];
        }
        return n;
    }
};