class Solution {
public:
    int numberOfSubstrings(string s) {
        map<char,int>mp;
        int n=s.size();
        int ans=0;
        mp['a']=-1;
        mp['b']=-1;
        mp['c']=-1;
        for(int i=0;i<n;i++){
            mp[s[i]]=i;
            if(mp['a'] != -1 && mp['b'] != -1 && mp['a'] != -1){
                int mi = min(mp['a'],mp['b']);
                mi = min(mi, mp['c']);
                ans+=(1+mi);
            }
        }
        return ans;
    }
};