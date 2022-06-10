class MinStack 
{
    stack<int> q;
    stack<int> decStack;
public:
    MinStack() 
    {
    }
    
    void push(int x) 
    {
        q.push(x);
        if(decStack.empty() or decStack.top()>=x)
        {
            decStack.push(x);
        }
    }
    
    void pop() 
    {
       if(decStack.top()==q.top())
                decStack.pop();
        q.pop();

    }
    
    int top() 
    {
        return q.top();
    }
    
    int getMin() 
    {
        return decStack.top();
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