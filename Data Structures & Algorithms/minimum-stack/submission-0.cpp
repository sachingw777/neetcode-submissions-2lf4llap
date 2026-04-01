class MinStack {
public:
    stack<int> stk;
    stack<int> minStack;
    MinStack() {}
    
    void push(int val) {
        stk.push(val);
        minStack.push(min(val, minStack.empty() ? val : minStack.top()));
    }
    
    void pop() {
        stk.pop();
        minStack.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
