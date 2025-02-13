#define ll long long
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        int ans = n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int m = wall[i].size();
            ll now = 0;
            for(int j=0;j<m-1;j++){
                now+=wall[i][j];
                mp[now]++;
                // cout<<mp[now]<<endl;
                int temp = n-mp[now];
                cout<<now<<" "<<temp<<endl;
                ans = min(ans, temp);
            }
            cout<<endl;
        }

        if(n==1 && wall[0].size()>1){
            return 0;
        }
        return ans;
    }
};