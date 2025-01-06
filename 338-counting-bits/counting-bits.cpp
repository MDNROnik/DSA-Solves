class Solution {
public:
    int fun(int now, vector<int>&mp){
        if(now == 0 || now == 1){
            return now;
        }
        if(mp[now]!=0){
            return mp[now];
        }
        int bit = now % 2;
        int remain = now / 2;
        return mp[now] = bit+fun(remain , mp);
    }
    vector<int> countBits(int n) {
        vector<int>ans;
        vector<int>mp(n+10, 0);
        for(int i=0;i<=n;i++){
            ans.push_back( fun(i, mp) );
        }
        return ans;
    }
};