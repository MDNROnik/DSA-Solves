class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        map<string,int>mp;
        for(int i=0;i<emails.size();i++){
            string s=emails[i];
            int at=0,plus=0,dot=0;
            string str="";
            for(int j=0;j<s.size();j++){
                if(s[j]=='@'){
                    at++;
                }
                if(at>0){
                    str.push_back(s[j]);
                }
                else{
                    if(plus>0){
                        continue;
                    }
                    if(s[j]=='+'){
                        plus++;
                    }
                    else if(s[j]=='.'){
                        dot++;
                    }
                    else{
                        str.push_back(s[j]);
                    }
                }
            }
            cout<<str<<endl;
            mp[str];
        }
        return mp.size();
    }
};