class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        vector<int>a;a.push_back(1);
        ans.push_back(a);
        numRows-=1;
        while(numRows--){
            int i=0,j=ans[ans.size()-1].size();
            vector<int>v=ans[ans.size()-1];
            vector<int>newa;
            for(int k=0;k<=j;k++){
                int up=0,left=0;
                if(k>=i && k<=j-1){
                    up+=v[k];
                }
                if(k-1>=i && k-1<=j-1){
                    left+=v[k-1];
                }
                newa.push_back(up+left);
            }












            ans.push_back(newa);
        }
        return ans;
    }
};