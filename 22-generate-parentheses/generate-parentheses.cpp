class Solution {
public:
    void dfs(int l, int r, string& path, vector<string>& ans) {
        if (l == 0 && r == 0) {
            ans.push_back(path);
            return;
        }

        if (l > 0) {
            path.push_back('(');
            dfs(l - 1, r, path, ans);
            path.pop_back();
        }
        if (l < r) {
            path.push_back(')');
            dfs(l, r - 1, path, ans);
            path.pop_back();
        }
    }
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else{
                //cout<<s[i]<<endl;
                if(st.size()==0){return false;}
                if(s[i]==')' && st.top()=='('){
                    //cout<<111<<endl;
                    st.pop();
                }
                else if(s[i]=='}' && st.top()=='{'){
                    //cout<<222<<endl;
                    st.pop();
                }
                else if(s[i]==']' && st.top()=='['){
                    //cout<<333<<endl;
                    st.pop();
                }
                else {return false;}
            }
        }
        if(st.size()>0){return false;}
        return true;
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s;
        dfs(n, n, s, ans);
        return ans;
    }
};