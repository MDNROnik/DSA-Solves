class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        map<pair<int,int>,bool>mp;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        int ones=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});mp[{i,j}]=1;
                }
                if(grid[i][j]==1){ones++;}
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int now = q.front().second;
            q.pop();
            ans = max(ans, now);

            if(i-1>=0 && grid[i-1][j]==1 && mp[{i-1,j}]==0){
                q.push( { {i-1,j},now+1 } );mp[{i-1,j}]=1;grid[i-1][j]=2;ones--;
            }
            if(i+1<n && grid[i+1][j]==1 && mp[{i+1,j}]==0){
                q.push( { {i+1,j},now+1 } );mp[{i+1,j}]=1;grid[i+1][j]=2;ones--;
            }

            if(j-1>=0 && grid[i][j-1]==1 && mp[{i,j-1}]==0){
                q.push( { {i,j-1},now+1 } );mp[{i,j-1}]=1;grid[i][j-1]=2;ones--;
            }
            if(j+1<m && grid[i][j+1]==1 && mp[{i,j+1}]==0){
                q.push( { {i,j+1},now+1 } );mp[{i,j+1}]=1;grid[i][j+1]=2;ones--;
            }
        }
        cout<<ones<<endl;
        if(ones>0){return -1;}
        return ans;
    }
};