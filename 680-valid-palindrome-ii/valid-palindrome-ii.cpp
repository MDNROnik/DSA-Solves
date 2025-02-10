class Solution {
public:
    bool fun(string &s, int i, int j, int count, int c, int &n, map<pair<pair<int,int>,int>, pair<int, bool>> &mp){
        // cout<<i<<" "<<j<<endl;
        if(i>j ){
            // cout<<c<<" in "<<count<<" "<<n<<endl;
            if(c>1 && count<=1){
                // cout<<1111<<endl;
                return true;
            }
            if(n==1 && c==1 && count<=1){
                // cout<<222<<endl;
                return true;
            }
            return false;
        }
        if(mp[{{i, j},count}].first==1){
            return mp[{{i, j}, count}].second;
        }
        bool first=false, second=false, thrid=false;
        if(s[i]==s[j]){
            first = fun(s, i+1, j-1, count, c+1, n, mp);
            if(first){mp[{{i, j}, count}].first = 1;  return mp[{{i, j}, count}].second = true;}
        }
        else if(s[i]!=s[j] && count<=1){
            second = fun(s, i+1, j, count+1, c, n, mp);
            if(second){mp[{{i, j}, count}].first = 1;  return mp[{{i, j}, count}].second = true;}
            thrid = fun(s, i, j-1, count+1, c, n, mp);
            if(thrid){mp[{{i, j}, count}].first = 1;  return mp[{{i, j}, count}].second = true;}
        }
        mp[{{i, j}, count}].first = 1;  return mp[{{i, j}, count}].second = false;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        n-=1;
        map<pair<pair<int,int>,int>, pair<int, bool>>mp;
        return fun(s, 0, n, 0, 0, n, mp);
    }
};