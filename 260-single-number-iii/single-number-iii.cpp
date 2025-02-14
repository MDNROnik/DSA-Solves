class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int num = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            num^=nums[i];
        }
        cout<<num<<endl;
        vector<int>v;
        for(int i=0;i<n;i++){
            int now = num^nums[i];
            // cout<<nums[i]<<" "<<now<<endl;
            int c=0, c2=0;
            for(int j=0;j<n;j++){
                // if(nums[j]==nums[i]){
                //     c++;
                // }
                if(now==nums[j]){
                    v.push_back(nums[j]);
                }
            }
            if(v.size()>1){
                v.clear();
            }
            else if(v.size()>0){
                v.push_back(nums[i]);break;
            }
        }
        return v;
    }
};