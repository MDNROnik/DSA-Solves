class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        map<int,vector<int>>vi;
        map<int,vector<int>>::reverse_iterator it;
        for(auto a=mp.begin();a!=mp.end();a++){
            vi[a->second].push_back(a->first);
        }
        for(it=vi.rbegin();it!=vi.rend();it++){
            for(int i=0;i<it->second.size();i++){
                ans.push_back(it->second[i]);
                if(ans.size()==k){break;}
            }
            if(ans.size()==k){break;}
        }

        return ans;
    }
};