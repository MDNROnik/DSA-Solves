class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& in, vector<string>& s) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<string, bool>inCheck, rCheck,ansCheck;
        int n=s.size();
        for(int i=0;i<n;i++){
            inCheck[s[i]]=true;
        }
        n=r.size();
        int m=n;
        vector<string>ans;
        while(m--){
            for(int i=0;i<n;i++){
                if(ansCheck[r[i]]==true){continue;}
                vector<string>v=in[i];
                int c=0, m=v.size();
                for(int j=0;j<m;j++){
                    if(inCheck[v[j]]==false){c++;break;}
                }
                if(c==0 && ansCheck[r[i]]==false){
                    ans.push_back(r[i]);
                    inCheck[r[i]]=true;
                    ansCheck[r[i]]=true;
                }
            }
        }
        
        return ans;
    }
};