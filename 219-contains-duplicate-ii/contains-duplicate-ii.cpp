class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,pair<bool,int>>mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(mp[nums[i]].first==false){
                mp[nums[i]].first=true;
                mp[nums[i]].second=i;
            }
            else{
                int j = mp[nums[i]].second;
                if( abs(i-j) <= k ){
                    return true;
                }
                else{
                    mp[nums[i]].second=i;
                }
            }
        }
        return false;
    }
};