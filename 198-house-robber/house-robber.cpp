class Solution {
public:
int solveUtil(int ind, vector<int>& arr, vector<int>& dp) {
    if (dp[ind] != -1)
        return dp[ind];

    if (ind == 0) 
        return arr[ind];
    if (ind < 0)  
        return 0;

    int pick = arr[ind] + solveUtil(ind - 2, arr, dp); 
    int nonPick = 0 + solveUtil(ind - 1, arr, dp);    

    return dp[ind] = max(pick, nonPick);
}
int solveUtil2(int n, vector<int>& arr, vector<int>& dp) {
    dp[0] = arr[0];
    
    for (int i = 1; i < n; i++) {
        int pick = arr[i];
        if (i > 1)
            pick += dp[i - 2];
        int nonPick = dp[i - 1];
        
        dp[i] = max(pick, nonPick);
    }
    
    return dp[n - 1];
}
    int rob(vector<int>& arr) {
        int prev = arr[0];   
        int prev2 = 0;       
        
        for (int i = 1; i < arr.size(); i++) {
            int pick = arr[i];  
            if (i > 1)
                pick += prev2;  
            
            int nonPick = 0 + prev;  
            
            int cur_i = max(pick, nonPick);  
            prev2 = prev;  
            prev = cur_i;
        }
        
        return prev; 
    }
};