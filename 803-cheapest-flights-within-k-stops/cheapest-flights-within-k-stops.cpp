class Solution {
public:
    long long fun(vector<vector<pair<int,int>>> &v, map< pair<int, pair<int,int> >, int > &mp, int src, int &dst, int k){
        if(src==dst && k>=-1){
            return 0;
        }
        else if(k<-1){
            return INT_MAX;
        }
        if(mp[{k, {src, dst}}]!=0){
            return mp[{k, {src, dst}}];
        }
        int n = v[src].size();
        long long cost = INT_MAX;
        for(int i=0;i<n;i++){
            // cout<<src<<" "<<v[src][i].first<<" "<<k-1<<endl;
            long long re = v[src][i].second + fun(v, mp, v[src][i].first, dst, k-1);
            cost = min(cost, re);
        }
        return mp[{k,{src, dst}}] = cost;
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>>v(n+10);

        int m = flights.size();
        for(int i=0;i<m;i++){
            int src = flights[i][0];
            int dist = flights[i][1];
            int cost = flights[i][2];
            v[src].push_back({dist, cost});
        }
        map< pair<int, pair<int,int> >, int > mp;

        int ans = fun(v, mp, src, dst, k);
        if(ans==INT_MAX){
            ans = -1;
        }
        return ans;
    }
};