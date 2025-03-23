class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long>v(n,0);
        int m=roads.size();
        for(int i=0;i<m;i++){
            int a=roads[i][0];
            int b=roads[i][1];
            v[a]++;
            v[b]++;
        }
        long long ans = 0;
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        long long count=n;
        for(int i=0;i<n;i++){
            ans=ans + (long long)count*v[i];
            count--;
        }
        return ans;
    }
};