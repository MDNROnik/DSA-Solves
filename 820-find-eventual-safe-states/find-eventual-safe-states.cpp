class Solution {
public: 
    bool dfs(vector<vector<int>> &v, vector<int> &visited, int node, vector<int> &track){
        int setBit = 0;
        int size = v[node].size();
        visited[node]=1;
        for(int i=0;i<size;i++){
            int edge = v[node][i];
            if(visited[edge]==0 && track[edge]==0){
                bool now = dfs(v, visited, edge, track);
                if(now==false){
                    setBit=1;break;
                }
                else {
                    track[edge]=2;
                }
            }
            else if(visited[edge]==0 && track[edge]==2){
                continue;
            }
            else{
                setBit=1;break;
            }
        }
        visited[node]=0;
        if(setBit==0){
            track[node]=2;
            return true;
        }
        else{
            track[node]=1;
            return false;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& v) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=v.size();
        vector<int>track(n, 0);
        vector<int>ans;
        for(int i=0;i<n;i++){
            vector<int>visited(n, 0);
            if(track[i]==1){continue;}
            bool now = dfs(v, visited, i, track);
            if(now==true){
                ans.push_back(i);
                track[i]=2;
            }
            else{
                track[i]=1;
            }
        }

        return ans;
        
    }
};