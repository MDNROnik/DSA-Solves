class Solution {
public:
    int check(string &s, int &n, int i, int l, int r, map<pair<int, stack<char>>, int> &mp, stack<char> &str){
        if(l<r){
            return 1;
        }
        if(n==i){
            if(l==r){
                return 2;
            }
            else{
                return 1;
            }
        }
        if(mp[{i, str}]!=0){
            return mp[{i, str}];
        }
        if(s[i]=='('){
            str.push('(');
            int ans = check(s, n, i+1, l+1, r, mp, str);
            if(ans==2){return mp[{i, str}]= 2;}
            str.pop();
        }
        if(s[i]==')' && str.size()>0 && str.top()=='('){
            str.pop();
            int ans = check(s, n, i+1, l, r+1, mp, str);
            if(ans==2){return mp[{i, str}]= 2;}
            str.push('(');
        }
        if(s[i]=='*'){
            int ans = check(s, n, i+1, l, r, mp, str);
            if(ans==2){return mp[{i, str}]= 2;}
        }
        if(s[i]=='*'){
            str.push('(');
            int ans = check(s, n, i+1, l+1, r, mp, str);
            if(ans==2){return mp[{i, str}]= 2;}
            str.pop();
        }
        if(s[i]=='*' && str.size()>0 && str.top()=='('){
            str.pop();
            int ans = check(s, n, i+1, l, r+1, mp, str);
            if(ans==2){return mp[{i, str}]= 2;}
            str.push('(');
        }
        
        return mp[{i, str}]=1;
    }
    bool checkValidString(string s) {
        int n=s.size();
        map<pair<int, stack<char>>, int>mp;
        stack<char> str;
        if( check(s, n, 0, 0, 0, mp, str) == 2){
            return 1;
        }
        else{
            return 0;
        }
    }
};