class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),zero=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==0){
        //         zero++;
        //     }
        // }
        // cout<<zero<<endl;
        // if(zero%3==1 ){
        //     return -1;
        // }
        int ans =INT_MAX, now=0;
        for(int i=0;i<n-2;i++){
            if(nums[i]==0){
                if(nums[i]==0){nums[i]=1;}
                if(nums[i+1]==0){nums[i+1]=1;}else{nums[i+1]=0;}
                if(nums[i+2]==0){nums[i+2]=1;}else {nums[i+2]=0;}
                now++;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zero++;
            }
        }
        if(zero>0){return -1;}
        ans = min(ans, now);
        return ans;
    }
};