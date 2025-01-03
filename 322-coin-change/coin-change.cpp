class Solution {
public:
    int fun(map<pair<int,int>  , int> &mp, vector<int> &coins, int amount, int index){
        //cout<<index<<" "<<amount<<endl;
        if(amount==0){
            return 0;
        }
        if(index>=coins.size() || amount<0){
            return 214748364;
        }
        if(mp[{index, amount}]>0){
            return mp[{index, amount}];
        }

        // int time = amount / coins[index];
        // int remain = amount % coins[index];

        int notpick = fun(mp, coins, amount, index+1);
        int pickandstay = 1 + fun(mp, coins, amount-coins[index], index);
        int pickandforward = 1 + fun(mp, coins, amount-coins[index], index+1);

        return mp[{index, amount}] = min( notpick, min(pickandstay,pickandforward) );
    }
    int coinChange(vector<int>& coins, int amount) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        map<pair<int,int> , int>mp;
        int ans =  fun(mp, coins, amount, 0);
        if(ans == 214748364){
            return -1;
        }
        return ans;
    }
};