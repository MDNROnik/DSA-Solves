class Solution {
public:
int minSumPathUtil(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    // Base cases
    if (i == 0 && j == 0)
        return matrix[0][0]; 
    
    if (dp[i][j] != -1)
        return dp[i][j]; 
    
    int up=0,left=0;
    if(i-1 < 0){
        up=INT_MAX;
    }
    else{
        up = matrix[i][j] + minSumPathUtil(i - 1, j, matrix, dp);
    }
    if(j-1<0){
        left=INT_MAX;
    }
    else{
        left = matrix[i][j] + minSumPathUtil(i, j - 1, matrix, dp);
    }
    
    return dp[i][j] = min(up, left);
}
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1)); 
        return minSumPathUtil(grid.size() - 1, grid[0].size() - 1, grid, dp);
    }
};