class Solution {
public:
    int fun(vector<int> &mp, int now, int n, vector<int> &cost){
        if(now==n){
            return 0;
        }
        if(now>n){
            return 1000;
        }
        if(mp[now]>-1){
            return mp[now];
        }
        int onestep = cost[now] + fun(mp, now+1, n, cost);
        int twostep = cost[now] + fun(mp, now+2, n, cost);
        return mp[now] = min(onestep, twostep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        //map<int, int>mp;
        vector<int> mp(1000, -1);
        int n = cost.size();
        int zero = fun(mp, 0, n, cost);
        int one = mp[1];
        cout<<zero<<" "<<one<<endl;
        return min(zero, one);
    }
};