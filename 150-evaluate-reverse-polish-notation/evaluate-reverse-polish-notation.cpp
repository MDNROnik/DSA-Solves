class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>st;
        int n = tokens.size();
        int now = 0;
        for(int i=0;i<n;i++){
            int first = 0, second = 0;
            if(tokens[i] == "+"){
                if(st.size()>1){
                    first = st.top();st.pop();
                    second = st.top();st.pop();
                }
                first+=second;
                st.push(first);
            }
            else if(tokens[i] == "-"){
                if(st.size()>1){
                    second = st.top();st.pop();
                    first = st.top();st.pop();
                }
                
                first-=second;
                st.push(first);
            }
            else if(tokens[i] == "*"){
                if(st.size()>1){
                    first = st.top();st.pop();
                    second = st.top();st.pop();
                }
                if(second==0){
                    st.push(second);
                    continue;
                }
                first*=second;
                st.push(first);
            }
            else if(tokens[i] == "/"){
                if(st.size()>1){
                    second = st.top();st.pop();
                    first = st.top();st.pop();
                }
                
                if(second==0){
                    st.push(second);
                    continue;
                }
                first/=second;
                st.push(first);
            }
            else{
                int num = std::stoi(tokens[i]);
                st.push(num);
            }
        }
        return st.top();
    }
};