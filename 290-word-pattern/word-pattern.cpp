class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n=pattern.size();
        int m=s.size();
        map<char, string>mp;
        map<string, pair<bool, char>>mp2;
        int j=0;
        for(int i=0;i<n;i++){
            string temp = mp[pattern[i]];
            string now = "";
            for(;j<m;j++){
                while(s[j]==' '){j++;}
                now = "";
                while(s[j]>='a' && s[j]<='z'){
                    now.push_back(s[j]);j++;
                }
                break;
            }
            cout<<pattern[i]<<" "<<now<<endl;
            if(now.size()>0 && temp.size()==0 && mp2[now].first == false){
                mp[pattern[i]] = now;
                mp2[now].first = true;
                mp2[now].second = pattern[i];
            }
            else if(temp==now && now.size()>0){ }
            else{
                return false;
            }
        }
        if(j<m){return false;}
        
        return true;
    }
};