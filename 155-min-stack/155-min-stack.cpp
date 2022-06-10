class MinStack 
{
    stack<int> q;
    stack<int> decStack;
public:
    MinStack() 
    {
        while(!q.empty())
        q.pop();
        while(!decStack.empty())
            decStack.pop(); 
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
        if(!q.empty()) 
        {
            if(decStack.top()==q.top())
                decStack.pop();
            q.pop();
        } 
    }
    
    int top() 
    {
        if(!q.empty()) 
            return q.top();
         return -1;
    }
    
    int getMin() 
    {
        if(!decStack.empty()) 
            return decStack.top();
        return -1;
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