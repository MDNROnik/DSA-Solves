class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>v(n+1);
        int node = n;
        int m = times.size();
        for(int i=0;i<m;i++){
            v[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        int ans = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dist(n+1, INT_MAX);
        pq.push({0, k});
        dist[k]=0;
        n-=1;
        while(!pq.empty()){
            int source = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            int m = v[source].size();
            for(int i=0;i<m;i++){

                if(dist[v[source][i].first] > dis+v[source][i].second){
                    if(dist[v[source][i].first]==INT_MAX){
                        n-=1;
                    }
                    dist[v[source][i].first] = dis+v[source][i].second;
                    pq.push({dist[v[source][i].first], v[source][i].first});
                }
            }
        }
        if(n>0){
            return -1;
        }
        for(int i=1;i<=node;i++){
            if(i==k){continue;}
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};