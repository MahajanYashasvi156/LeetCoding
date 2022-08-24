class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) 
    {
        stack<int> s;
        int n = temperatures.size()-1;
        vector<int> ans(n+1,0);
        
        for(int i = n;i>=0;i--)
        {
            while(!s.empty() and temperatures[s.top()]<=temperatures[i])
                s.pop();

            
            if(!s.empty())
            {
                ans[i] = s.top() - i;
            }
            s.push(i);
        }
        return ans;
    }
};