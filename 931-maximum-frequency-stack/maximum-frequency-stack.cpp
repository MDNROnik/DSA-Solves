class FreqStack {
public:
int count=0;
unordered_map<int,int>mp,mp2;
stack<pair<int,int>>st;
int maxi= 0;
    FreqStack() {
        // mp.clear();
        // st.clear();
        count=0;
    }
    
    void push(int val) {
        int now = mp[val];
        if(mp2[now]>0){
            mp2[now]--;
        }
        mp[val]++;
        now = mp[val];
        mp2[now]++;
        st.push({val, count});count++;
        maxi = max(maxi, mp[val]);
    }
    
    int pop() {
        stack<pair<int,int>>st2;
        int temp=0;
        cout<<maxi<<endl;
        while(!st.empty()){
            if(mp[st.top().first] == maxi){
                temp = st.top().first;
                st.pop();break;
            }
            else{
                st2.push(st.top());
                st.pop();
            }
        }
        while(!st2.empty()){
            st.push(st2.top());
            st2.pop();
        }
        mp[temp]--;
        mp2[mp[temp]]++;
        mp2[maxi]--;
        if(mp2[maxi]==0){
            maxi--;
        }
        cout<<temp<<endl<<endl;
        return temp;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */