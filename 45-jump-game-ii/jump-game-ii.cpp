#define ll long long
class Solution {
public:

    ll fun(vector<int> &nums, int index, int &n, vector<ll> &v, vector<bool> &vis){
        if(index==n-1){
            return 1;
        }

        if( vis[index] ){return v[index];}
        
        ll miniStep = INT_MAX;
        
        for(int i=1;i<=nums[index];i++){
            if(index+i < n){
                ll value = fun(nums, index+i, n, v, vis);
                miniStep = min(miniStep, value);
            }
        }
        vis[index] = true;
        return v[index] = miniStep+1;
    }
    int jump(vector<int> &nums) 
    {
            ios_base::sync_with_stdio(false);
            cin.tie(NULL);
            int n=nums.size();
            vector<ll>v(n+10 , INT_MAX);
            vector<bool>vis (n+10, false);
            if(n==1){return 0;}
            fun(nums, 0, n, v, vis);
            v[0]-=1;

            if(v[0]==INT_MAX){return -1;}
            return v[0];
    }
};