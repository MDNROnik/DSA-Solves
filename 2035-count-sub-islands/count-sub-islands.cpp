class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        vector<vector<int>>visited(m, vector<int>(n,0));
        vector<vector<int>>visited2(m, vector<int>(n,0));
        int ans=0, first=0, second=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid1[i][j]==1 && visited[i][j]==0){
                    queue<pair<int,int>>q;first++;
                    q.push({i, j});
                    visited[i][j]=1;
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        // cout<<row<<" "<<col<<endl;
                        q.pop();

                        if(row+1<m && visited[row+1][col]==0 && grid1[row+1][col]==1){
                            q.push({row+1, col});
                            visited[row+1][col]=1;
                        }
                        if(row-1>=0 && visited[row-1][col]==0 && grid1[row-1][col]==1){
                            q.push({row-1, col});
                            visited[row-1][col]=1;
                        }

                        if(col+1<n && visited[row][col+1]==0 && grid1[row][col+1]==1){
                            q.push({row, col+1});
                            visited[row][col+1]=1;
                        }
                        if(col-1>=0 && visited[row][col-1]==0 && grid1[row][col-1]==1){
                            q.push({row, col-1});
                            visited[row][col-1]=1;
                        }
                    }
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool IN=false, makeIsland=true;
                if(grid2[i][j]==1 && visited2[i][j]==0){
                    queue<pair<int,int>>q;second++;
                    IN=true;
                    q.push({i, j});
                    visited2[i][j]=1;
                    if(visited[i][j]==0 || grid1[i][j]==0 ){makeIsland=false;}
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        // cout<<row<<" "<<col<<endl;
                        q.pop();

                        if(row+1<m && visited2[row+1][col]==0 && grid2[row+1][col]==1){
                            q.push({row+1, col});
                            visited2[row+1][col]=1;
                            if(visited[row+1][col]==0 || grid1[row+1][col]==0 ){makeIsland=false;}
                        }
                        if(row-1>=0 && visited2[row-1][col]==0 && grid2[row-1][col]==1){
                            q.push({row-1, col});
                            visited2[row-1][col]=1;
                            if(visited[row-1][col]==0 || grid1[row-1][col]==0){makeIsland=false;}
                        }

                        if(col+1<n && visited2[row][col+1]==0 && grid2[row][col+1]==1){
                            q.push({row, col+1});
                            visited2[row][col+1]=1;
                            if(visited[row][col+1]==0 || grid1[row][col+1]==0){makeIsland=false;}
                        }
                        if(col-1>=0 && visited2[row][col-1]==0 && grid2[row][col-1]==1){
                            q.push({row, col-1});
                            visited2[row][col-1]=1;
                            if(visited[row][col-1]==0 || grid1[row][col-1]==0){makeIsland=false;}
                        }
                    }
                }
                if(IN==true && makeIsland==true){
                    // cout<<i<<" "<<j<<endl;
                    // cout<<"YES"<<endl;
                    ans++;
                }
            }
        }

        //second graph
        
        // cout<<first<<" "<<second<<endl;
        return ans;
    }
};