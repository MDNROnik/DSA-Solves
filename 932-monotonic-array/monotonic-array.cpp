class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        int i=0, pattern = 0;
        if(n==1){return true;}
        else if(n==2){
            return true;
        }
        else {
            for(i=0;i<n-1;i++){
                if(nums[i]==nums[i+1]){continue;}
                else{break;}
            }
            if(i < n-1){
                if(nums[i]<=nums[i+1]){pattern = 1;}
                else{
                    pattern = 2;
                }
            }
        }
        if(pattern == 0){return true;}
        while( i < n-1 ){
            if(pattern==1 && nums[i]<=nums[i+1]){
                
            }
            else if(pattern==2 && nums[i]>=nums[i+1]){
                
            }
            else{
                return false;
            }
            i++;
        }
        return true;
    }
};