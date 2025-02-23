class StockSpanner {
public: 
// stack<int>st;
vector<int>st;
    StockSpanner() {}
    int next(int price) {
        int ans = 0, n = st.size();
        if(n==0){
            st.push_back(price);
            ans++;
        }
        else{
            int m = n-1, in=0;
            for(int i=n-1;i>=0;i--){
                if(st[i]<=price){
                    ans++;
                }
                else{
                    ans++;in++;break;
                }
            }
            if(in==0){
                ans++;
            }
            st.push_back(price);
        }
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */