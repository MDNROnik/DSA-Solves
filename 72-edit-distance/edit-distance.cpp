class Solution {
public:
    int fun(string &word1, int i, string &word2, int j, vector<vector<vector<int>>> &v, int matchs, int &n, int &m, int mode){
       
        if(i==n && j==m){
            cout<<1<<endl;
            if(matchs==m){
                return 0;
            }
            else{
                return 10000;
            }
        }
        else if(i==n && j<m){
            return (m-j);
        }
        else if(i<n && j==m){
            return (n-i);
        }
        if(v[i][j][mode] != -1){
            return v[i][j][mode];
        }
        int match=10000, remove=10000, replace=10000, insert=10000;
        if(word1[i]==word2[j]){
            match = fun(word1, i+1, word2, j+1, v, matchs+1, n, m, 1);
        }
        else{
            remove = 1 + fun(word1, i+1, word2, j, v, matchs, n, m, 2);
            replace = 1 + fun(word1, i+1, word2, j+1, v, matchs+1, n, m, 3);
            insert = 1 + fun(word1, i, word2, j+1, v, matchs+1, n, m, 4);
        }
        return v[i][j][mode] = min(match, min(remove, min(replace, insert)));
    }
    int minDistance(string word1, string word2) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n=word1.size(), m=word2.size();
        vector<vector<vector<int>>>v(n+10,vector<vector<int>>(m+10, vector<int>(10, -1)));

        return fun(word1, 0, word2, 0, v, 0, n, m, 0);
    }
};