class MinStack {
private:
    stack<int> st;
    stack<int> min_st;

public:
    void push(int val) {
        st.push(val);
        if (min_st.empty() || val <= getMin())
            min_st.push(val);
    }

    void pop() {
        if (st.top() == getMin())
            min_st.pop();
        st.pop();
    }

    int top() { return st.top(); }

    int getMin() { return min_st.top(); }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
