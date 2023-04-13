/*
Link - https://leetcode.com/problems/validate-stack-sequences/submissions/
*/
class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        stack<int> s;
        int i = 0;
        int j = 0;
        
        while(i< pushed.size())
        {
            while(i< pushed.size() and popped[j]!=pushed[i])
            {
                s.push(pushed[i++]);
            }
            i++;
            j++;
            while(!s.empty() and j<popped.size() and popped[j] == s.top() )
            {
                s.pop();
                j++;
            }
        }
        return s.empty() and j==popped.size();
    }
};