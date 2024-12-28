class Solution {
public:
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        map<pair<int,int>,bool>visited;
        int ans= 0, finalans =0 ;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = 0;
                if(grid[i][j]==1 && visited[{i,j}]==0){
                    
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    visited[{i,j}]=1;
                    //cout<<i<<" --- "<<j<<endl;
                    ans= 0;
                    while(!q.empty()){
                        ans ++; 
                        int row = q.front().first;
                        int col = q.front().second;
                        //cout<<row<<" "<<col<<endl;
                        if(row-1>=0 && visited[{row-1,col}]==0 && grid[row-1][col]==1){
                            //cout<<"UP"<<endl;
                            q.push({row-1,col});
                            visited[{row-1,col}]=1;
                        }
                        if(row+1<n && visited[{row+1,col}]==0 && grid[row+1][col]==1){
                            //cout<<"DOWN"<<endl;
                            q.push({row+1,col});
                            visited[{row+1,col}]=1;
                        }

                        if(col-1>=0 && visited[{row,col-1}]==0 && grid[row][col-1]==1){
                            //cout<<"LEFT"<<endl;
                            q.push({row,col-1});
                            visited[{row,col-1}]=1;
                        }
                        if(col+1<m && visited[{row,col+1}]==0 && grid[row][col+1]==1){
                            //cout<<"RIGHT"<<endl;
                            q.push({row,col+1});
                            visited[{row,col+1}]=1;
                        }
                        q.pop();
                    }
                }
                finalans = max(finalans , ans);
            }
        }
        return finalans;
    }
};