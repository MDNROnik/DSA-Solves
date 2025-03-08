class Solution {
public:
    int partitionString(string s) {
        vector<int>v(26, 0);
        int n = s.size(), ans = 0;
        for(int i=0;i<n;i++){
            int ascii = s[i]-97;
            if( v[ascii] == 1 ){
                for(int j=0;j<26;j++){
                    v[j]=0;
                }
                v[ascii] = 1;
                ans++;
            }
            else{
                v[ascii] = 1;
            }
        }
        ans++;
        return ans;
    }
};