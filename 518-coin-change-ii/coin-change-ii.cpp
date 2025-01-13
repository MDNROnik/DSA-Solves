class Solution {
public:
    int fun(vector<vector<int>> &v, int amount, int index, vector<int>& coins, int &n){
        //cout<<index<<" "<<amount<<endl;
        if(amount==0){
            return 1;
        }
        else if(amount<0 || index>=n){
            return 0;
        }
        if(v[index][amount] != -1){
            return v[index][amount];
        }
        int take = fun(v, amount-coins[index], index, coins, n);
        int not_take = fun(v, amount, index+1, coins, n);

        return v[index][amount] = (take + not_take);
    }
    int change(int amount, vector<int>& coins) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = coins.size();
        vector<vector<int>>v(n+10, vector<int>(amount+10, -1));
        return fun(v, amount, 0, coins, n);
    }
};