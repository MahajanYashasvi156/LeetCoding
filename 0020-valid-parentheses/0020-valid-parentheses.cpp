class Solution {
public:
    bool isValid(string s) 
    {
        stack<char> myStack;
        for(int i=0;i<s.size();i++)
        {
            if(myStack.size()>0 and (s[i]==')' and myStack.top()=='(' or s[i]=='}' and myStack.top()=='{' or s[i]==']' and myStack.top()=='[' ) )
            {
                myStack.pop();
            }
            else
                myStack.push(s[i]);            
        }
        if(myStack.empty())
            return true;
        return false;
    }
};