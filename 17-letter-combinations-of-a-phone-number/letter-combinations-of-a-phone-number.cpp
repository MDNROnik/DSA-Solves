class Solution {
public: 
    void fun(vector<string> &ans, map<char,string> &mp, int index, string now, string &d){
        if(index == d.size()){
            ans.push_back(now);
            return;
        }
        string s = mp[d[index]];
        for(int i=0;i<s.size();i++){
            now.push_back(s[i]);
            fun(ans, mp, index+1, now, d);
            now.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0){
            return ans;
        }

        map<char,string>mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string now = "";
        fun(ans, mp, 0, now, digits);
        return ans;
    }
};