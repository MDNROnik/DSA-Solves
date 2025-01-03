class Solution {
public:
    int fun(vector<vector<int>> &mp, vector<int> &coins, int amount, int index, int n){
        
        //cout<<index<<" "<<amount<<endl;
        if(amount==0){
            return 1;
        }
        if(index>=n || amount<0){
            return 0;
        }
        if(mp[index][amount]!= -1){
            return mp[index][amount];
        }

        // int time = amount / coins[index];
        // int remain = amount % coins[index];

        int notpick = fun(mp, coins, amount, index+1, n);
        int pickandstay =  fun(mp, coins, amount-coins[index], index, n);
        // int pickandforward = 1 + fun(mp, coins, amount-coins[index], index+1, n);

        int pickandforward = 0;
        // cout<<notpick<<" "<<pickandstay<<" "<<pickandforward<<endl;
        return mp[index][amount] = notpick+ pickandstay;
    }
    int change(int amount, vector<int>& coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        // map<pair<int,int> , int>mp;
        int n = coins.size();
        vector<vector<int>>mp(n, vector<int>(amount+1, -1));
        int ans =  fun(mp, coins, amount, 0, n);
        
        return ans;
    }
};