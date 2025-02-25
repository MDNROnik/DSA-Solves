class MyQueue {
public:
stack<int>st;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int>st2;
        while(!st.empty()){
            st2.push(st.top());st.pop();
        }
        int value = st2.top();st2.pop();
        while(!st2.empty()){
            st.push(st2.top());st2.pop();
        }
        return value;
    }
    
    int peek() {
        stack<int>st2;
        while(!st.empty()){
            st2.push(st.top());st.pop();
        }
        int value = st2.top();
        while(!st2.empty()){
            st.push(st2.top());st2.pop();
        }
        return value;
    }
    
    bool empty() {
        return st.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */