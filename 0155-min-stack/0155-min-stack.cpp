class MinStack {
public:
    stack<int> st;
    vector<int> res;
    MinStack() {}

    void push(int val) {
        st.push(val);
        auto idx = lower_bound(res.begin(), res.end(), val);
        res.insert(idx, val);
    }

    void pop() {
        auto idx = lower_bound(res.begin(), res.end(), st.top());
        if (idx != res.end())
            res.erase(idx);
        if (!st.empty())
            st.pop();
    }

    int top() { 
        return !st.empty() ? st.top() : -1;
    }

    int getMin() { 
        return !st.empty() ? res[0] : -1;
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