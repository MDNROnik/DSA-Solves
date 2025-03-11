class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n=s.size();
        map<char, pair<bool, char>>mp;
        map<char, bool>mp2;
        for(int i=0;i<n;i++){
            if(mp[s[i]].first == false && mp2[t[i]]==false){
                mp[s[i]].first=true;
                mp[s[i]].second=t[i];
                mp2[t[i]]=true;
            }
            else{
                if(mp[s[i]].second == t[i]){

                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};