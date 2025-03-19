class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int>less, great;
        int n=nums.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]<pivot){
                less.push_back(nums[i]);
            }
            else if(nums[i]==pivot){
                c++;
            }
            else{
                great.push_back(nums[i]);
            }
        }
        vector<int>ans;
        ans=less;
        while(c--){
            ans.push_back(pivot);
        }
        ans.insert(ans.end(), great.begin(), great.end());
        return ans;
    }
};