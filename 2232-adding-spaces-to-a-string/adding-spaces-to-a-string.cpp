class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int n=s.size(), m=spaces.size();
        int i=0, j=0;
        // cout<<n<<" "<<m<<endl;
        for(;i<n;){
            // cout<<i<<" "<<j<<endl;
            if( j<m &&  (i == spaces[j]) ){
                ans.push_back(' ');j++;
            }
            else{
                ans.push_back(s[i]);i++;
            }
        }
        return ans;
    }
};