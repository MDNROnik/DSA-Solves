class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int minus=0,count=0;
        int product=1, n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
                continue;
            }
            product*=nums[i];
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(count==1){
                    ans.push_back(product);
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if(count>0){
                    ans.push_back(0);
                }
                else{
                    ans.push_back(product/nums[i]);
                }
            }
        }
        return ans;
    }
};