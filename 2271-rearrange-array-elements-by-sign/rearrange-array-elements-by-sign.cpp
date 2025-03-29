class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans;
        int m=nums.size(), p=0, n=0, now = 1;
        
        for(int i=0;i<m;i++){
            for(;p<m;){
                if(nums[p]>0){
                    ans.push_back(nums[p]);p++;break;
                }
                p++;
            }
            for(;n<m;){
                if(nums[n]<0){
                    ans.push_back(nums[n]);n++;break;
                }
                n++;
            }
        }
        
        return ans;
    }
};