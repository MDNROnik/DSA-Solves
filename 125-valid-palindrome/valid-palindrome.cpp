class Solution {
public:
    bool isPalindrome(string s) {
        string str,str2;
        for(int i=0;i<s.size();i++){
            if('a'<=s[i] && s[i]<='z'){
                str.push_back(s[i]);
                str2.push_back(s[i]);
            }
            else if('A'<=s[i] && s[i]<='Z'){
                str.push_back(tolower(s[i]));
                str2.push_back(tolower(s[i]));
            }
            else if('0'<=s[i] && s[i]<='9'){
                str.push_back(s[i]);
                str2.push_back(s[i]);
            }
        }
        reverse(str2.begin(),str2.end());
        cout<<str<<" "<<str2<<endl;
        if(str==str2){
            return true;
        }
        else{
            return false;
        }
    }
};