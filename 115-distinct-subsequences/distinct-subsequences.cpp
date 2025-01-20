class Solution {
public:
    int fun(string &s, string &t, vector<vector<int>> &v, int i, int j, int &n, int &m){
        if(i==n && j==m){
            return 1;
        }
        else if(i==n){
            return 0;
        }
        else if(j==m){
            return 1;
        }
        if(v[i][j]!=-1){
            return v[i][j];
        }
        int take =0, nottake=0;
        if(s[i]==t[j]){

            take = fun(s, t, v, i+1, j+1, n, m);
        }
        nottake = fun(s, t, v, i+1, j, n, m);
        return v[i][j] = (take+nottake);
    }
    int numDistinct(string s, string t) {
        int n=s.size(), m=t.size();
        vector<vector<int>>v(n+10, vector<int>(m+10, -1));
        return fun(s, t, v, 0, 0, n, m);
    }
};