class Solution {
public:
    bool isSubsequence(string s, string t) {
        map<char, int>mp;
        int n=s.size(), m=t.size();
        int pre = 0;
        for(int i=0;i<n;i++){
            bool in=false;
            for(int j=pre;j<m;j++){
                // cout<<s[i]<<" "<<t[j]<<endl;
                if(t[j]==s[i]){
                    
                    pre = j+1;in=true;break;
                }
            }
            if(in==false){
                return false;
            }
        }
        return true;
    }
};