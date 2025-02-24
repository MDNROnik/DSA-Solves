class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        int i=0, j=0;
        string ans = "";
        for(;i<n && j<m;i++, j++){
            ans.push_back(word1[i]);
            ans.push_back(word2[j]);
        }
        // cout<<i<<" "<<j<<endl;
        while(i<n){
            ans.push_back(word1[i]);i++;
        }
        while(j<m){
            ans.push_back(word2[j]);j++;
        }
        return ans;
    }
};