class MinStack {
private:
    stack<long long> st;
    long long mini=LLONG_MAX;
public:
    MinStack() {
       

        
    }
    
    void push(int val) {
        long long v=val;
        if(st.empty()){
            st.push(v);
            mini=min(mini,v);
            return;
        }
        if(mini>v){
            st.push(2*v-mini);
            mini=v;
            return;
        }
        st.push(v);
            
    }
    
    void pop() {
        long long x=st.top();
        if(x<mini){
            mini=2*mini-x;
            st.pop();
            return;
            
        }
        st.pop();
        if(st.empty()){
            mini=LLONG_MAX;
        }
    }
    
    int top() {
        long long x=st.top();
        if(x<mini){
            return (int) mini;
        }
        
        return (int) x;
        

        
    }
    
    int getMin() {
        return (int) mini;
        
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
