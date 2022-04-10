class Solution {
public:
    int calPoints(vector<string>& ops) 
    {
        stack<int> s;
        for(auto temp:ops)
        {
            if(temp=="+")
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.push(a);
                s.push(a+b);
            }
            else if(temp=="D")
            {
                int a = s.top();
                s.push(2*a);
            }
            else if(temp=="C")
            {
                s.pop();
            }
            else
            {
                s.push(stoi(temp));
            }
        }
        int sum =0;
        while(s.empty()==false)
        {
            sum = sum + s.top();
            s.pop();
            
        }
        return sum;
    }
};