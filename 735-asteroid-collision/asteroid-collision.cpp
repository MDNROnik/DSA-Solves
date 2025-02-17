class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        int n=as.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.size()==0 ){
                st.push(as[i]);
            }
            else if(st.top()<0 && as[i]<0){
                 st.push(as[i]);
            }
            else if(st.top()>=0 && as[i]>=0){
                 st.push(as[i]);
            }
            else{
                st.push(as[i]);
                while(st.size()>=2){
                    int first = st.top();st.pop();
                    int second = st.top();st.pop();
                    if( (first<0 && second>=0) ){
                        int firstSize = abs(first);
                        int secondSize = abs(second);
                        if(firstSize==secondSize){

                        }
                        else if(firstSize>secondSize){
                            st.push(first);
                        }
                        else{
                            st.push(second);
                        }
                    }
                    else{
                        st.push(second), st.push(first);break;
                    }
                }
            }
        }
        n=st.size();
        vector<int>ans(n, -1);

        while(n--){
            ans[n]=st.top();st.pop();
        }
        return ans;
    }
};