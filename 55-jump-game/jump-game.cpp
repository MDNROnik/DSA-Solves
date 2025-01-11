class Solution {
public:
    bool canJump(vector<int>& nums) {
        int init = 0, n=nums.size();
        for(int i=0;i<n;i++){
            int step = nums[i]+i;
            //cout<<step<<" "<<init<<endl;
            if(nums[i]==0 && step==init && i!=n-1){
                return false;
            }

            init = max(init, step);
        }
        if(init < n-1){
            cout<<111<<endl;
            return false;
        }
        return true;
    }
};