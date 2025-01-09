class Solution {
public:
    int fun( vector<vector<int>> &mp, int indexi, int indexj, string &text1, string &text2, int &n, int &m){
        //cout<<indexi<<" "<<indexj<<endl;
        if(indexi>=n || indexj>=m){
            return 0;
        }
        if(mp[indexi][indexj] != -1){
            return mp[indexi][indexj];
        }
        int notequal1 = 0, notequal2 = 0, equal=0;
        if(text1[indexi]!=text2[indexj]){
            notequal1 = fun(mp, indexi+1, indexj, text1, text2, n, m);
            notequal2 = fun(mp, indexi, indexj+1, text1, text2, n, m);
        }
        if(text1[indexi] == text2[indexj]){
            equal = 1 + fun(mp, indexi+1, indexj+1, text1, text2, n, m);
        }
        return mp[indexi][indexj] = max (equal , max(notequal1, notequal2) )  ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m=text2.size(); 
        vector<vector<int>>mp(n,vector<int>(m, -1));
        return fun(mp, 0, 0,text1, text2, n, m);
    }
};