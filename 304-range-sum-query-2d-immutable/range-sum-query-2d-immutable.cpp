vector<vector<int>>rows_cols(200+10, vector<int>(200+10, 0));
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        cout<<n<<" "<<m<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                rows_cols[i+1][j+1] = matrix[i][j] + rows_cols[i][j+1] + rows_cols[i+1][j];
                rows_cols[i+1][j+1]-=rows_cols[i][j];
                // cout<<matrix[i][j]<<" ";
            }
            // cout<<endl;
        }
        // cout<<111<<endl;
        // for(int i=0;i<n+1;i++){
        //     for(int j=0;j<m+1;j++){
        //         cout<<rows_cols[i+1][j+1] <<" ";
        //     }
        //     cout<<endl;
        // }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // cout<<rows_cols[row2+1][col2+1]<<endl;
        return ((rows_cols[row2+1][col2+1] - (rows_cols[row2+1][col1] + rows_cols[row1][col2+1])  )  + rows_cols[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */