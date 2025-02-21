class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int>st;
        int ans = 0;
        for(int i=0;i<n;i++){
            // int myint1 = stoi(str1);
            string s = operations[i];
            if(s.size()==1){
                if(s[0]>='0' && s[0]<='9'){
                    int myint1 = stoi(s);
                    st.push(myint1);
                }
                else if(s[0]=='+'){
                    if(st.size()>=2){
                        int now = 0;
                        int first = st.top();st.pop();
                        int second = st.top();st.pop();
                        st.push(second);st.push(first);
                        now = first+second;
                        st.push(now);
                    }
                }
                else if(s[0]=='D'){
                    if(st.size()>=1){
                        int now = 0;
                        int first = st.top();st.pop();
                        st.push(first);
                        now = first+first;
                        st.push(now);
                    }
                }
                else{
                    if(st.size()>=1){
                        st.pop();
                    }
                }
            }
            else{
                int myint1 = stoi(s);
                st.push(myint1);
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};