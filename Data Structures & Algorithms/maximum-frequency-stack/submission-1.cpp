class FreqStack {
public:
    unordered_map<int, int> cnt;
    vector<stack<int>> stacks;
    FreqStack() {
        stacks.push_back(stack<int>());
    }
    
    void push(int val) {
        int resVal = cnt[val]++;
        if(resVal == stacks.size()) {
            stacks.push_back(stack<int>());
        }
        stacks[resVal].push(val);
    }
    
    int pop() {
        stack<int>& st = stacks.back();
        int res = st.top();
        st.pop();
        if(st.empty()) stacks.pop_back();
        cnt[res]--;
        return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */