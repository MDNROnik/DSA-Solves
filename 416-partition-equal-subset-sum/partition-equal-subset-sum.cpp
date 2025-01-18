class Solution {
public:
    bool fun(vector<int>& nums, vector<vector<int>>& v, int i, int &n, int range){
        // cout<<range<<" "<<i<<endl;
        if(i==n){
            return range==0;
        }
        if(range==0){
            return 1;
        }
        if(range<0){
            return 0;
        }
        if(v[range][i] != -1){
            return v[range][i];
        }
        // cout<<"GO"<<endl;
        bool take = fun(nums, v, i+1, n, range-nums[i]);
        if(take==1){
            return v[range][i] = 1;
        }
        bool not_take = fun(nums, v, i+1, n, range);
        if(not_take==1){
            return v[range][i] = 1;
        }
        return v[range][i] = 0;
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size(), sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        //sort(nums.begin(),nums.end());
        if( (sum%2) != 0){
            return false;
        }
        vector<vector<int>>v(sum+10, vector<int>(n+10, -1));
        return fun(nums, v, 0, n, sum/2);
    }
};