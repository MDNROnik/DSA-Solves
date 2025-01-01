class Solution {
public:
    int fun(vector<int> &ans, vector<int>&stones, int index, int siz, int sum, int mainsum, map<pair<int,int>, pair<bool,int>> &mp){
        if(siz==index){
            int remain = mainsum-sum;
            remain = abs(sum-remain);
            ans.push_back(remain);
            return remain;
        }
        if(mp[{sum, index}].first == true){
            return mp[{sum,index}].second ;
        }

        int notpick = fun(ans, stones, index+1, siz, sum, mainsum, mp);
        int pick = fun(ans, stones, index+1, siz, sum+stones[index], mainsum, mp);
        mp[{sum, index}].first = true;
        return mp[{sum,index}].second = min(notpick, pick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        map<pair<int,int>, pair<bool,int>>mp;
        int sum=0, n=stones.size();
        for(int i=0;i<n;i++){
            sum+=stones[i];
        }
        vector<int>ans;
        return fun(ans, stones, 0, n,0, sum,mp); 
    }
};