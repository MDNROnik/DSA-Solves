class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;
        map<int,vector<int>>mp2;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }

        for(auto it=mp.begin();it!=mp.end();it++){
            mp2[it->second].push_back(it->first);
        }

        vector<int>ans;

        for(auto it=mp2.rbegin();it!=mp2.rend();it++){
            vector<int>v=it->second;
            for(int i=0;i<v.size();i++){
                if(k>0){
                    ans.push_back(v[i]);
                    k--;
                }
                else{
                    break;
                }
            }
            if(k<=0){break;}
        }
        
        
        return ans;
    }
};