class MinStack 
{
    stack<int> q;
    stack<int> minq;
public:
    MinStack() 
    {
        
    }
    
    void push(int x) 
    {
        q.push(x);
        if(minq.empty() or minq.top()>=x)
        {
            minq.push(x);
        }
    }
    
    void pop() 
    {
        if(!q.empty()) 
        {
            if(minq.top()==q.top())
                minq.pop();
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
        if(!minq.empty()) 
            return minq.top();
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