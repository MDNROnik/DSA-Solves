class Solution {
public:
    bool canJump(vector<int>& nums) {
        int result = 1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0 && i+1==n){
                int count=0;
                for(int j=i;j>=0;j--){
                    if(count<=nums[j]){
                        count=0;
                        break;
                    }
                    count++;
                }
                if(count!=0){
                    result=0;
                    break;
                }
            }
            else if(nums[i]==0){
                int count=1;
                for(int j=i;j>=0;j--){
                    if(count<=nums[j]){
                        count=0;
                        break;
                    }
                    count++;
                }
                if(count!=0){
                    result=0;
                    break;
                }
            }
        }
        if(result || n==1){
            return true;
        }
        else{
            return false;
        }
    }
};