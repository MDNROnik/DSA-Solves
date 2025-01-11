class Solution {
public:
    int fun(vector<int> &nums, int index, int &n, vector<int> &v){
        if(index==n){
            return 0;
        }
        else if(index==n-1){
            return 1;
        }

        if(v[index] != -1){return v[index];}

        for(int i=1;i<=nums[index];i++){
            if( fun(nums, index+i, n, v) == 1  ){
                return v[index] = 1;
            }
        }
        return v[index] = 0;
    }
    bool canJump(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        vector<int>v(n+10 , -1);
        return bool(fun(nums, 0, n, v));
    }
};