class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int>vec,vec2;
        int ans=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            vec.push_back(sum);
        }
        sum=0;
        for(int i=nums.size()-1;i>=0;i--){
            sum+=nums[i];
            vec2.push_back(sum);
        }
        reverse(vec2.begin(),vec2.end());
        
        for(int i=0;i<nums.size();i++){
            if(vec[i]==vec2[i]){
                ans=i;break;
            }
        }
        return ans;
    }
};