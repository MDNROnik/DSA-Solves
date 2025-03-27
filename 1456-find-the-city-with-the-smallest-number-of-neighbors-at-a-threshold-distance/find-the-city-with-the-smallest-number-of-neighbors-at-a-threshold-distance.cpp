class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int thr) {
        vector<vector<pair<int,int>>>v(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            int weight = edges[i][2];
            v[from].push_back({to, weight});
            v[to].push_back({from, weight});
        }
        map<int,vector<int>>mp;
        int ans = INT_MIN, c=INT_MAX;
        for(int i=0;i<n;i++){
            vector<int>visited(n, INT_MAX);
            visited[i]=0;
            queue<pair<int,int>>q;
            q.push({i, 0});
            int count = 0;
            while(!q.empty()){
                int node = q.front().first;
                int wei = q.front().second;
                q.pop();
                int size = v[node].size();
                for(int j=0;j<size;j++){
                    int edge = v[node][j].first;
                    int weight = v[node][j].second;
                    if( (wei+weight <= thr) && (visited[edge] > (wei+weight)) ){
                        if(visited[edge]==INT_MAX){
                            count++;
                        }
                        q.push({edge, (wei+weight)});
                        visited[edge]=(wei+weight);
                    }
                }
            }
            // cout<<i<<" "<<count<<endl;
            if(count>=0){
                // mp[count].push_back(i);
                if(count<c){
                    c=count;
                    ans = i;
                }
                else if(count==c){
                    if(ans<i){
                        ans = i;
                    }
                }
            }
        }
        return ans;
    }
};