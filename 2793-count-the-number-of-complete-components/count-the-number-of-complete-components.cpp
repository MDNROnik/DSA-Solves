class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        map<int,vector<int>>e;
        for(int i=0;i<m;i++){
            int from = edges[i][0];
            int to = edges[i][1];
            e[from].push_back(to);
            e[to].push_back(from);
        }
        int ans=0;
        vector<int>visited(n, 0);
        vector<vector<int>>paths(n, vector<int>(n,0));
        for(int i=0;i<n;i++){

            if(visited[i]==0){
                visited[i] = 1;
                queue<int>q;
                q.push(i);
                int vertex=0, path = 0;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    vertex++;
                    for(int j=0;j<e[node].size();j++){
                        int edge = e[node][j];
                        int x=node, y=edge;
                        if(x>y){
                            swap(x,y);
                        }
                        if(paths[x][y]==0){
                            path++;
                            paths[x][y]=1;
                        }
                        if(visited[edge]==0){
                            visited[edge] = 1;
                            q.push(edge);
                        }
                    }
                }
                int v=vertex-1;
                int require = (v*(v+1))/2;
                cout<<i<<" "<<vertex<<" "<<path<<endl;
                if(vertex==1){ans++;}
                else if(vertex==2 && path==1){
                    ans++;
                }
                else if(require==path){
                    ans++;
                }
            }
        }
        return ans;
    }
};