class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size(),n=grid1[0].size() , ans=0;

        vector<vector<int>>visited2(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                bool IN=false, makeIsland=true;
                if(grid2[i][j]==1 && visited2[i][j]==0){
                    queue<pair<int,int>>q;
                    IN=true;
                    q.push({i, j});
                    grid2[i][j]=0;
                    if(grid1[i][j]==0 ){makeIsland=false;}
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        if(row+1<m && grid2[row+1][col]==1){
                            q.push({row+1, col});
                            grid2[row+1][col]=0;
                            if( grid1[row+1][col]==0 ){makeIsland=false;}
                        }
                        if(row-1>=0 && grid2[row-1][col]==1){
                            q.push({row-1, col});
                            grid2[row-1][col]=0;
                            if( grid1[row-1][col]==0){makeIsland=false;}
                        }

                        if(col+1<n && grid2[row][col+1]==1){
                            q.push({row, col+1});
                            grid2[row][col+1]=0;
                            if( grid1[row][col+1]==0){makeIsland=false;}
                        }
                        if(col-1>=0 && grid2[row][col-1]==1){
                            q.push({row, col-1});
                            grid2[row][col-1]=0;
                            if( grid1[row][col-1]==0){makeIsland=false;}
                        }
                    }
                }
                if(IN==true && makeIsland==true){
                    ans++;
                }
            }
        }

        return ans;
    }
};