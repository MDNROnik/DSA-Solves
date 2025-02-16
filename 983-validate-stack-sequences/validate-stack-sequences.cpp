class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        int n = pushed.size(), m = popped.size();
        int i=0, j=0;
        while(i<n){
            while(st.size()>0 && j<m && st.top()==popped[j]){
                st.pop();j++;
            }
            // cout<<i<<" "<<j<<endl;
            st.push(pushed[i]);i++;
            while(st.size()>0 && j<m && st.top()==popped[j]){
                st.pop();j++;
            }
            // cout<<i<<" "<<j<<endl;
        }
        // cout<<i<<" "<<j<<endl;
        if(i==n && j==m){
            return true;
        }
        else{
            return false;
        }
    }
};