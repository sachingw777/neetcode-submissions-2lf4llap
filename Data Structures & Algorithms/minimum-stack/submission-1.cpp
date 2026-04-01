class MinStack {
public:
    stack<pair<int,int>> st;
    MinStack() {
    }
    
    void push(int val) {
        int min;

        if(st.empty()){
            min = val;
        }else{
            auto [top, topMin] = st.top();
            min = (val < topMin) ? val : topMin;
        }

        st.push({val,min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
