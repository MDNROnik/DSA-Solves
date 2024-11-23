class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;
        map<char,bool>mp2;
        int ans=0;
        int l=0,r=0;

        while(r<s.size()){
            if(mp2[s[r]] == false){
                ans = max(ans, ((r-l)+1) );
                mp2[s[r]]=true;
                mp[s[r]]=r;r++;
            }
            else{
                int now = mp[s[r]];
                if(now<l){
                    ans = max(ans, ((r-l)+1) );
                    mp[s[r]]=r;
                    r++;
                }
                else{
                    l=mp[s[r]]+1;
                    mp[s[r]]=r;
                    r++;
                }
            }
        }
        // r--;
        // ans = max(ans, ((r-l)+1) );
        return ans;
    }
};