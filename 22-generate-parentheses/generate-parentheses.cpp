class Solution {
public:
    void solve(int n,vector<string>&ans,string s){
        if(n==0){
            bool a = isValid(s);
            if(a==1){
                ans.push_back(s);
            }
            return ;
        }
        s.push_back('(');
        solve(n-1,ans,s);
        s.pop_back();
        s.push_back(')');
        solve(n-1,ans,s);
        s.pop_back();
        return ;
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
        n*=2;
        string s;
        solve(n,ans,s);
        return ans;
    }
};