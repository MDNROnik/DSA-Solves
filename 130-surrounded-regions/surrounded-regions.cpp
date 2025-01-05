class Solution {
public:
    bool fun(vector<vector<char>>& board, vector<vector<bool>>& visited, int &n, int &m , int i , int j){
        visited[i][j]=true;
        if(i==0 || i==n-1 || j==0 || j==m-1){
            return true;
        }
        
        bool up=false, down=false, left=false, right=false;
        if( i-1>=0 && board[i-1][j]=='O' && visited[i-1][j]==false){
            up = fun(board, visited, n, m, i-1, j);
        }
        if( i+1<n && board[i+1][j]=='O' && visited[i+1][j]==false){
            down = fun(board, visited, n, m, i+1, j);
        }

        if( j-1>=0 && board[i][j-1]=='O' && visited[i][j-1]==false){
            left = fun(board, visited, n, m, i, j-1);
        }
        if( j+1<m && board[i][j+1]=='O' && visited[i][j+1]==false){
            right = fun(board, visited, n, m, i, j+1);
        }

        return up || down || left || right;
    }
    void setx(vector<vector<char>>& board, vector<vector<bool>>& visited, int &n, int &m , int i , int j){
        board[i][j]='X';
        if( i-1>=0 && board[i-1][j]=='O' && visited[i-1][j]==true){
            
            setx(board, visited, n, m, i-1, j);
        }
        if( i+1<n && board[i+1][j]=='O' && visited[i+1][j]==true){
            
            setx(board, visited, n, m, i+1, j);
        }

        if( j-1>=0 && board[i][j-1]=='O' && visited[i][j-1]==true){
            
            setx(board, visited, n, m, i, j-1);
        }
        if( j+1<m && board[i][j+1]=='O' && visited[i][j+1]==true){
            
            setx(board, visited, n, m, i, j+1);
        }

        return ;
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(board[i][j]=='O' && visited[i][j]==false){
                    bool ans = fun(board, visited, n, m, i, j);
                    //cout<<i<<" "<<j<<endl;
                    //cout<<ans<<endl;
                    if (ans==false){
                        setx(board, visited, n, m, i, j);
                    }
                }
            }
        }
        
        return;
    }
};