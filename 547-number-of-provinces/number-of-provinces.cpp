class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int ans=0;
        vector<vector<int>>v(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                // cout<<i<<" "<<j<<" "<<isConnected[i][j]<<endl;
                if(isConnected[i][j]==1 && i!=j){
                    // cout<<"IN"<<endl;
                    v[i].push_back(j);
                }
            }
            cout<<endl;
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<" -> ";
        //     for(int j=0;j<v[i].size();j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                queue<int>q;
                q.push(i);
                visited[i]=1;
                ans++;
                while(!q.empty()){
                    int node = q.front();
                    int size = v[node].size();
                    q.pop();
                    // cout<<"NOW "<<node<<" and size "<<size<<endl;
                    for(int j=0;j<size;j++){
                        int edge = v[node][j];
                        // cout<<"EDGES "<<edge<<" ";
                        if(visited[edge]==0){
                            visited[edge]=1;
                            q.push(edge);
                        }
                    }
                }
                // cout<<endl;
            }
        }
        
        return ans;
    }
};