class MyStack {
private:
    stack<int> myStack;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        myStack.push(x);
    }
    
    int pop() {
        int val = myStack.top(); // store the value before removing it
    myStack.pop();           // now remove
    return val;
    }
    
    int top() {
        return myStack.top();
    }
    
    bool empty() {
        return myStack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */