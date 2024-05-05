class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        bool ans=false;
        map<int,bool>mp;
        for(int i=0;i<nums.size();i++){
            if(mp[nums[i]]==false){
                mp[nums[i]]=true;
            }
            else{
                ans=true;break;
            }
        }
        return ans;
    }
};