class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tem) {
        int n=tem.size();
        stack<pair<int,int>>st;
        vector<int>ans(n,0);
        st.push({tem[0],0});
        int i=1;
        while(i<n){
            int value = tem[i], index= i;
            while(st.size()>0){
                pair<int,int>p=st.top();
                if(p.first<value){
                    st.pop();
                    ans[p.second]=index-p.second;
                }
                else{
                    break;
                }
            }
            st.push({value,index});
            i++;
        }
        return ans;
    }
};