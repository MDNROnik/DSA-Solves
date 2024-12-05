class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid.size();
        vector<int>v((n*m)+10,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //cout<<grid[i][j]<<" ";
                v[grid[i][j]]++;
            }
        }
        //cout<<endl;
        vector<int>ans;
        ans.push_back(0);
        ans.push_back(0);
        for(int i=1;i<=n*m;i++){
            //cout<<n*m<<endl;
            if(v[i]==0){
                ans[1]=i;
            }
            else if(v[i]>1){
                ans[0]=i;
            }
            if(ans[0]>0 && ans[1]>0){break;}
        }
        return ans;
    }
};