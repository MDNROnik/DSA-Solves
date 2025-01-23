class Solution {
public:
    int fun(vector<vector<vector<int>>> &v, string &s, string &p, int i, int j, int &n , int &m, int step){
        if(i==n && j==m){
            return 1;
        }
        if(i==n+9 || j==m+9){
            // cout<<2<<endl;
            return 0;
        }
        if(v[i][j][step]!=-1){
            // cout<<2<<endl;
            return v[i][j][step];
        }
        if(i>n){
            // cout<<2<<endl;
            return 0;
        }
        else if(j>m){
            // cout<<2<<endl;
            return 0;
        }

        if(s[i]==p[j]){
            // cout<<1<<endl;
            cout<<i<<" "<<j<<" "<<1<<endl;
            if(fun(v, s, p, i+1, j+1, n, m, 1)){return v[i][j][step] = 1;}
        }
        if(s[i]!=p[j] && j+1<m && p[j+1]=='*'){
            cout<<i<<" "<<j<<" "<<2<<endl;
            if(fun(v, s, p, i, j+1, n, m, 2)){return v[i][j][step] = 1;}
        }
        if(p[j]=='.'){
            cout<<i<<" "<<j<<" "<<3<<endl;
            if(fun(v, s, p, i+1, j+1, n, m, 3)==1){
                return v[i][j][step] = 1;
            }
        }
        if(p[j]=='*'){
            // cout<<1<<endl;
            cout<<i<<" "<<j<<" "<<4<<endl;
            if(fun(v, s, p, i, j+1, n, m, 4)){return v[i][j][step] = 1;}
            if(j-1>=0){
                if(p[j-1]!='.'){
                    if(p[j-1]==s[i]){
                        cout<<i<<" "<<j<<" "<<5<<endl;
                        if(fun(v, s, p, i+1, j, n, m, 5)){return v[i][j][step] = 1;}
                        cout<<i<<" "<<j<<" "<<6<<endl;
                        if(fun(v, s, p, i+1, j+1, n, m, 6)){return v[i][j][step] = 1;}
                    }
                }
                else{
                    cout<<i<<" "<<j<<" "<<7<<endl;
                    if(fun(v, s, p, i+1, j, n, m, 7)){return v[i][j][step] = 1;}
                    cout<<i<<" "<<j<<" "<<8<<endl;
                    if(fun(v, s, p, i+1, j+1, n, m, 8)){return v[i][j][step] = 1;}
                }
            }
        }
        if(s[i]==p[j] && j+1<m && p[j+1]=='*'){
            cout<<i<<" "<<j<<" "<<9<<endl;
            if(fun(v, s, p, i, j+1, n, m, 2)){return v[i][j][step] = 1;}
        }

        return v[i][j][step] = 0;
    }
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<vector<int>>>v(n+10, vector<vector<int>>(m+10, vector<int>(10, -1)));
        // vector<vector<int>>v(n+10, vector<int>(m+10, -1));
        return fun(v, s, p, 0, 0, n, m, 0);
    }
};