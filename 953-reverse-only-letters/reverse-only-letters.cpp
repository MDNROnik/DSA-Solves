class Solution {
public:
    string reverseOnlyLetters(string s) {
        string str="";
        int j=s.size()-1;
        while(j>=0){
            if( (s[j]>='A' && s[j]<='Z') ||(s[j]>='a' && s[j]<='z') ){
                str.push_back(s[j]);
            }
            j--;
        }
        
        string ans="";
        j=0;

        for(int i=0;i<s.size();){
            if( (s[i]>='A' && s[i]<='Z') ||(s[i]>='a' && s[i]<='z') ){
                ans.push_back(str[j]);
                j++;i++;
            }
            else{
                ans.push_back(s[i]);i++;
            }
            
        }
        return ans;
    }
};