class Solution {
public:
    Solution() {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    bool fun(vector<vector<char>>& board, string &word, int index, int i, int j, vector<vector<int>> &visited, int n, int m){

        visited[i][j]=1;
        
        if(index>=word.size()){

            return true;
        }

        if(i-1>=0 && visited[i-1][j]==0 && board[i-1][j]==word[index]){
            //cout<<"UP"<<endl;
            if( fun(board, word, index+1, i-1, j, visited, n, m) ){
                return true;
            }
        }
        if(i+1<n && visited[i+1][j]==0 && board[i+1][j]==word[index]){
            //cout<<"DOWN"<<endl;
            if( fun(board, word, index+1, i+1, j, visited, n, m) ){
                return true;
            }
        }
        if(j-1>=0 && visited[i][j-1]==0 && board[i][j-1]==word[index]){
            //cout<<"LEFT"<<endl;
            if( fun(board, word, index+1, i, j-1, visited, n, m) ){
                return true;
            }
        }
        if(j+1<m && visited[i][j+1]==0 && board[i][j+1]==word[index]){
            //cout<<"RIGHT"<<endl;
            if( fun(board, word, index+1, i, j+1, visited, n, m) ){
                return true;
            }
        }

        visited[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(), m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(board[i][j]==word[0]){
                    vector<vector<int>> visited (n, vector<int> (m, 0));
                    //cout<<i<<" "<<j<<endl;
                    if( fun(board, word, 1, i, j, visited, n, m) ){
                        return true;
                    }
                }

            }
        }
        cout<<111<<endl;
        return false;
    }
};