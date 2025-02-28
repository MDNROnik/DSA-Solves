class Solution {
public:
    
    long long gridGame(vector<vector<int>>& grid2) {
        int n = grid2[0].size();
        int minValue = INT_MAX;
        vector<vector<long long>> grid(2,vector<long long>(n, 0));
        grid[0][0] = grid2[0][0];
        grid[1][0] = grid2[1][0];
        for(int i=1;i<n;i++){

            grid[0][i]+=grid[0][i-1]+grid2[0][i];
            grid[1][i]+=grid[1][i-1]+grid2[1][i];
        }
        long long ans = LLONG_MAX	;
        for(int i=0;i<n;i++){
            long long sum = grid[0][n-1]-grid[0][i];
            long long sum2= 0;
            if(i!=0){
                sum2= grid[1][i-1];
            }
            
            // cout<<i<<endl;
            // cout<<sum<<" "<<sum2<<endl;
            long long now = max(sum, sum2);
            ans = min(ans, now);
            // cout<<ans<<endl<<endl;
        }
        return ans;
    }
};