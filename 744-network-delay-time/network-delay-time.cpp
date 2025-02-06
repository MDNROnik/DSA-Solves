class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>v(n+10);
        int node = n;
        int m = times.size();
        for(int i=0;i<m;i++){
            int source = times[i][0];
            int target = times[i][1];
            int time = times[i][2];
            v[source].push_back({target,time});
        }
        int ans = INT_MIN;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int>dist(n+10, INT_MAX);
        pq.push({0, k});
        dist[k]=0;
        n-=1;
        while(!pq.empty()){
            int source = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            int m = v[source].size();
            for(int i=0;i<m;i++){
                int target = v[source][i].first;
                int spentTime = v[source][i].second;
                cout<<source<<" "<<target<<" "<<dist[target]<<" "<<dis+spentTime<<endl;
                if(dist[target] > dis+spentTime){
                    if(dist[target]==INT_MAX){
                        n-=1;
                    }
                    dist[target] = dis+spentTime;
                    pq.push({dis+spentTime, target});
                }
            }
        }
        cout<<n<<endl;
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