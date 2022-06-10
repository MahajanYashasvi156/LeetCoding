class Solution 
{
public:
    int evalRPN(vector<string>& A) 
    {
        stack<int> s;
        int x ;
        int y;
        for(int i = 0;i<A.size();i++)
        {
            if(A[i] == "+")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x+y);
            }
            else if(A[i] == "-")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x-y);
            }
            else if(A[i] == "/")
            {
               y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x/y);
            }
            else if(A[i] == "*")
            {
                y = s.top();
                s.pop();
                x = s.top();
                s.pop();
                s.push(x*y);
            }
            else
            {
                s.push(stoi(A[i]));
            }
        }
        return s.top();   
    }
};