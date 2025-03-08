class Solution {
public:
    int partitionString(string s) {
        vector<int>v(26, 0);
        int n = s.size(), ans = 0;
        for(int i=0;i<n;i++){
            int a = s[i];
            int ascii = s[i]-97;
            // cout<<i<<" "<<ascii<<" "<<v[ascii];
            if( v[ascii] == 1 ){
                cout<<" 1 IN"<<endl;
                for(int j=0;j<26;j++){
                    v[j]=0;
                }
                v[ascii] = 1;
                ans++;
            }
            else{
                // cout<<" 2 IN "<<endl;
                v[ascii] = 1;
            }
        }
        ans++;
        return ans;
    }
};