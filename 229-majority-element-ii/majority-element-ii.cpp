
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        map<int, pair<int,int>>mp;
        vector<int>ans;
        int c = floor(n / 3)+1;
        cout<<c<<endl;
        for(int i=0;i<n;i++){
            mp[nums[i]].first++;
            if(mp[nums[i]].first>=c && mp[nums[i]].second==0){
                mp[nums[i]].second=1;
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};