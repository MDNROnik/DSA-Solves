class Solution {
public:
    int fun(vector<vector<int>> &v, vector<int>& prices, int i, int mode, int &n){
        if(i==n){
            return 0;
        }
        if(v[i][mode] != -1){
            return v[i][mode];
        }
        int profit = 0;
        if(mode == 0){
            profit = max(
                (-prices[i]+fun(v, prices, i+1, 1, n)),
                fun(v , prices, i+1, mode, n)
            );
        }
        else if(mode==1){
            profit = max(
                prices[i],
                fun(v , prices, i+1, mode, n)
            );
        }
        return v[i][mode] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>v(n+10, vector<int>(4,  -1));
        int ans = 0;
        return max(ans,fun(v,prices, 0, 0, n) );
    }
};