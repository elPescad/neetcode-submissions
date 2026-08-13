class MinStack {
public:
    stack<int> st;
    stack<int> minSt;
    MinStack() {}
    
    void push(int val) {
        st.push(val);

        if(minSt.empty()) {
            minSt.push(val);
        } else {
            val = min(minSt.top(), val);
            minSt.push(val);
        }
    }
    
    void pop() {
        st.pop();
        minSt.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
