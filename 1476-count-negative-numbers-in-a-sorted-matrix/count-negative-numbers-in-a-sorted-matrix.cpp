class Solution {
public:
    int countNegatives(vector<vector<int>>& v) {
        int ans=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            int now = upper_bound(v[i].rbegin(),v[i].rend(),-1)-v[i].rbegin();
            ans+=now;
        }
        return ans;
    }
};