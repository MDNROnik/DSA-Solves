class Solution {
public:
    int fun(vector<vector<int>> &vec, int row, int col, int m, int n){
        if(row==m-1 && col==n-1){
            vec[row][col] = 1;
            return vec[row][col] ;
        }
        if(row>=m || col>=n){
            return 0;
        }

        if( vec[row] [col]  != -1 ){
            return vec[row][col] ;
        }

        int down = fun(vec, row+1, col, m, n);
        int right = fun(vec, row, col+1, m, n);

        return vec[row][col]  = (down + right);

    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> vec(m, vector<int> (n, -1));
        return fun(vec, 0, 0, m, n);
    }
};