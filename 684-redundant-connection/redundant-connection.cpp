class Solution {
public:
    int cycle(int root, vector<vector<int>> &v, vector<pair<int,bool>> &visited, int parent, int level, int &a){
        level+=1;
        int n=v[root].size();
        visited[root].first=level;
        for(int i=0;i<n;i++){
            int node = v[root][i];
            if(visited[node].first==0){
                if(cycle(node, v, visited, root, level, a)>1){
                    visited[node].second=true;
                    return 2;
                }
            }
            else if(visited[node].first>=1 && node==parent){

            }
            else if(visited[node].first>=1 && node!=parent){
                a=visited[node].first;
                visited[node].second=true;
                return 2;
            }
        }
        return 1;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>>v(n+10);
        for(int i=0;i<n;i++){
            v[edges[i][0]].push_back(edges[i][1]);
            v[edges[i][1]].push_back(edges[i][0]);
        }
        vector<pair<int,bool>>visited(n+10,{0, false});
        int a = 0;
        cycle(1, v, visited, -1, 0, a);
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(0);
        for(int i=n-1;i>=0;i--){
            if(visited[edges[i][0]].first>=a && visited[edges[i][1]].first>=a 
            && visited[edges[i][0]].second==1 && visited[edges[i][1]].second==1){
                ans[0]=(edges[i][0]);ans[1]=(edges[i][1]);break;
            }
        }
        return ans;
    }
};