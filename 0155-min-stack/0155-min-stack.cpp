class MinStack {
    stack<long long> st;
    long long mini = INT_MAX;
public:
    MinStack() {
        mini = LLONG_MAX;
    }
    
    void push(int value) {
        if(st.empty()){
             st.push(value);
             mini = value;
        }
        else{
            if(mini < value) st.push(value);
            else{
                st.push(2LL*value - mini);
                mini = value;
            }
        }
    }
    
    void pop() {
        long long n = st.top();
        st.pop();
        if(st.empty()){
            mini = LLONG_MAX;
            return;
        } 
        if(n < mini){
            mini = 2*mini - n;
        }
        
    }
    
    int top() {
        if(st.empty()) return -1;
        long long n = st.top();
        if(mini <= n) return n;
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */