class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans = 0;
        vector<int>v(n,0);
        vector<vector<int>>visited(n, vector<int>(n,0));
        int m=roads.size();
        for(int i=0;i<m;i++){
            int a = roads[i][0];
            int b= roads[i][1];
            v[a]++;v[b]++;
            visited[a][b]=1;
            visited[b][a]=1;
            // cout<<a<<" "<<b<<endl;
            // cout<<visited[a][b]<<" "<< visited[a][b]<<endl;
        }
        // cout<<endl;
        for(int i=0;i<n;i++){
            int now = 0;
            for(int j=i+1;j<n;j++){
                int total = v[i]+v[j];
                // cout<<i<<" "<<j<<endl; 
                // cout<<visited[i][j]<<" "<< visited[j][i]<<endl;
                // cout<<v[i]<<" " <<v[j]<<endl;
                // cout<<total<<endl;
                if(visited[i][j]==1 || visited[j][i]==1){
                    total--;
                    ans = max(ans, total);
                }
                else{
                    ans = max(ans, total);
                }
            }
        }
        return ans;
    }
};