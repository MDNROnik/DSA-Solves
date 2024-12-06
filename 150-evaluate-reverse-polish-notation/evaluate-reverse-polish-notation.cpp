class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long>st;
        // stringstream geek;
        // geek << s;
        // int x = 0;
        // geek >> x;
        long long ans=0;
        long long n=tokens.size();
        for(int i=0;i<n;i++){

            if(tokens[i] =="+"){
                long long second = st.top();st.pop();
                long long first = st.top();st.pop();
                long long ans =first+second;
                st.push(ans);
            }
            else if(tokens[i]=="-"){
                long long second = st.top();st.pop();
                long long first = st.top();st.pop();
                long long ans =first-second;
                st.push(ans);
            }
            else if(tokens[i]=="/"){
                long long second = st.top();st.pop();
                long long first = st.top();st.pop();
                long long ans =first/second;
                st.push(ans);
            }
            else if(tokens[i]=="*"){
                long long second = st.top();st.pop();
                long long first = st.top();st.pop();
                long long ans =first*second;
                st.push(ans);
            }
            else{
                //cout<<tokens[i]<<endl;
                stringstream geek;
                geek << tokens[i];
                long long x = 0;
                geek >> x;
                st.push(x);
            }
        }
        ans=st.top();
        return ans;   
    }
};