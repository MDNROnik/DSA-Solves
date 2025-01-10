class Solution {
public:
    int fun(vector<vector<vector<int>>> &mp, vector<int>& prices, int index, int type, int pre, int &n){
        if(index == n){
            //cout<<"END"<<endl;
            return 0;
        }
        if(mp[index][type][pre]!=-1){
            //cout<<"MAP "<<index<<" "<<type<<" "<<pre<<endl;
            return mp[index][type][pre];
        }
        int buy = INT_MIN;
        int not_buy = INT_MIN;
        int sell = INT_MIN;
        int not_sell = INT_MIN;
        int rest = INT_MIN;
        if(type == 0){
            //cout<<"NOT_BUY "<<index<<" "<<type<<" "<<pre<<endl;
            not_buy = fun(mp, prices, index+1, 0, 0, n);
            //cout<<"BUY "<<index<<" "<<type<<" "<<pre<<endl;
            buy = fun(mp, prices, index+1, 1, index, n);
            buy = max(buy, not_buy);
        }
        else if(type==1){
            //cout<<"NOT_SELL "<<index<<" "<<type<<" "<<pre<<endl;
            not_sell = fun(mp, prices, index+1, 1, pre, n)  ;
            //cout<<"SELL "<<index<<" "<<type<<" "<<pre<<endl;
            sell = (prices[index]-prices[pre])+fun(mp, prices, index+1, 2, 0, n), 
            sell = max(sell, not_sell);
        }
        else{
            //cout<<"REST "<<index<<" "<<type<<" "<<pre<<endl;
            rest = fun(mp, prices, index+1, 0, 0, n);
        }
        return mp[index][type][pre] = max(max(buy, sell),rest);
    }
    int maxProfit(vector<int>& prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = prices.size();
        vector<vector<vector<int>>> mp(n+10, vector<vector<int>>(4, vector<int>(n+10, -1)));
        //vector<vector<int>>v(n+10,vector<int>(4, -1));
        return fun(mp, prices, 0, 0, 0, n);
    }
};