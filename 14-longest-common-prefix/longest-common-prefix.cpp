class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int n = strs.size();
        for(int i=0;;i++){
            int c=0;
            char now = strs[0][i];
            for(int j=0;j<n;j++){
                if(strs[j].size()>i && strs[j][i]==now ){c++;}
            }
            if(c==n){
                ans.push_back(now);
            }
            else{
                break;
            }
        }
        return ans;
    }
};