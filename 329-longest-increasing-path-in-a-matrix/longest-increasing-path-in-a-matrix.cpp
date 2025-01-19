class Solution {
public:
    int fun(vector<vector<int>>& matrix, vector<vector<int>>& v, int i, int j, int n, int m){
        if(i==n && j==m){
            return 0;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        int left = 0, right = 0, up = 0, down = 0;
        //cout<<matrix[i][j]<<endl;
        if(i-1>=0 && matrix[i-1][j]<matrix[i][j]){
            cout<<"UP"<<endl;
            up = 1 + fun(matrix, v, i-1, j, n, m);
        }
        if(j-1>=0 && matrix[i][j-1]<matrix[i][j]){
            cout<<"LEFT"<<endl;
            left = 1+ fun(matrix, v, i, j-1, n, m);
        }
        if(i+1<n && matrix[i+1][j]<matrix[i][j]){
            cout<<"DOWN"<<endl;
            down = 1+ fun(matrix, v, i+1, j, n, m);
        }
        if(j+1<m && matrix[i][j+1]<matrix[i][j]){
            cout<<"RIGHT"<<endl;
            right = 1+ fun(matrix, v, i, j+1, n, m);
        }
        return v[i][j] = max( max(left, right), max(up, down)  );
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<vector<int>>v(n+10, vector<int>(m+10, -1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                //cout<<i<<" "<<j<<endl;
                fun(matrix, v, i, j, n, m);
                ans = max(ans, v[i][j]);
            }

        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m ;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
        

        return ans+1;
    }
};