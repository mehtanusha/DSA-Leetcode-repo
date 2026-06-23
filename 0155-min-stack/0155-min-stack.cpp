class MinStack {
public:
    stack<long long> st;
    long long mini;

    MinStack() {
        mini = INT_MAX;
    }

    void push(int value) {
        if(st.empty()) {
            st.push(value);
            mini = value;
        }
        else if(value >= mini) {
            st.push(value);
        }
        else {
            st.push(2LL * value - mini);
            mini = value;
        }
    }

    void pop() {
        if(st.empty()) return;

        long long top = st.top();
        st.pop();

        if(top < mini) {
            mini = 2LL * mini - top;
        }
    }

    int top() {
        if(st.empty()) return -1;

        long long top = st.top();

        if(top < mini) return mini;

        return top;
    }

    int getMin() {
        return mini;
    }
};