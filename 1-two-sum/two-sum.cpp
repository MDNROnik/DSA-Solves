class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }
        vector<int>ans;

        for(int i=0;i<nums.size();i++){
            int remain = target-nums[i];

            if(mp[remain].size() > 0){
                int indexi=i,indexj;
                vector<int>v=mp[remain];
                int count=0;
                for(int j=0;j<v.size();j++){
                    if(i!=v[j]){
                        indexj=v[j];count=1;
                        ans.push_back(indexi),ans.push_back(indexj);
                        break;
                    }
                }
                if(count==1){break;}
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};