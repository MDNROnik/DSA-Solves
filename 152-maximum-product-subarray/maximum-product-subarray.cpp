class Solution {
public:
    
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int mul=0, ans = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                ans = max(ans, 0);
                mul=0; 
            }
            else{
                ans = max(ans, nums[i]);
                if(mul==0){
                    mul=nums[i];
                }
                else{
                    cout<<mul<<endl;
                    mul*=nums[i];
                    cout<<mul<<endl;
                }
                ans = max(ans, mul);
            }
        }
        mul=0;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                ans = max(ans, 0);
                mul=0; 
            }
            else{
                ans = max(ans, nums[i]);
                if(mul==0){
                    mul=nums[i];
                }
                else{
                    mul*=nums[i];
                }
                ans = max(ans, mul);
            }
        }
        return ans;
    }
};