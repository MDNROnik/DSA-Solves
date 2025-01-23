class Solution {
public:
    int fun(vector<vector<vector<int>>> &v, string &s, string &p, int i, int j, int &n , int &m, int step){
        if(i==n && j==m){
            return 1;
        }
        if(i==n+9 || j==m+9){
            return 0;
        }
        if(v[i][j][step]!=-1){
            return v[i][j][step];
        }
        if(i>n){
            return 0;
        }
        else if(j>m){
            return 0;
        }

        if(s[i]==p[j]){
            if(fun(v, s, p, i+1, j+1, n, m, 1)){return v[i][j][step] = 1;}
        }
        if(s[i]!=p[j] && j+1<m && p[j+1]=='*'){
            if(fun(v, s, p, i, j+1, n, m, 2)){return v[i][j][step] = 1;}
        }
        if(p[j]=='.'){
            if(fun(v, s, p, i+1, j+1, n, m, 3)==1){
                return v[i][j][step] = 1;
            }
        }
        if(p[j]=='*'){
            if(fun(v, s, p, i, j+1, n, m, 4)){return v[i][j][step] = 1;}
            if(j-1>=0){
                if(p[j-1]!='.'){
                    if(p[j-1]==s[i]){
                        if(fun(v, s, p, i+1, j, n, m, 5)){return v[i][j][step] = 1;}
                        if(fun(v, s, p, i+1, j+1, n, m, 6)){return v[i][j][step] = 1;}
                    }
                }
                else{
                    if(fun(v, s, p, i+1, j, n, m, 7)){return v[i][j][step] = 1;}
                    if(fun(v, s, p, i+1, j+1, n, m, 8)){return v[i][j][step] = 1;}
                }
            }
        }
        if(s[i]==p[j] && j+1<m && p[j+1]=='*'){
            if(fun(v, s, p, i, j+1, n, m, 2)){return v[i][j][step] = 1;}
        }

        return v[i][j][step] = 0;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<vector<int>>>v(n+10, vector<vector<int>>(m+10, vector<int>(10, -1)));

        return fun(v, s, p, 0, 0, n, m, 0);
    }
};