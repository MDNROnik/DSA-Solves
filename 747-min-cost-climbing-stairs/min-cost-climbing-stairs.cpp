class Solution {
public:
    int solve1(int n,vector<int>& cost,vector<int>& dp){
        if(n==0 || n==1){
            dp[n]=cost[n];
            return cost[n];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=(cost[n]+min(solve1(n-1,cost,dp),solve1(n-2,cost,dp)));
    }
    int solve2(int n,vector<int>& cost){
        vector<int>dp(n+1);
        dp[0]=cost[0];
        dp[1]=cost[1];
        for(int i=2;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        return min(dp[n-1],dp[n-2]);
    }
    
    
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1,-1);
        //return min(solve1(n-1,cost,dp),solve1(n-2,cost,dp));
        return solve2(n,cost);
    }
};