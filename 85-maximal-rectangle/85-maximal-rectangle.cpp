class Solution 
{
    vector<int> nextSmaller(vector<int>&A)
    {
       vector<int> result(A.size());
       stack<int> s;

       for(int i = A.size()-1;i>=0;i--)
       {
           while(!s.empty() and A[s.top()]>=A[i])
                s.pop();
            if(!s.empty())
                result[i] = s.top();
            else
                result[i] = A.size();
            s.push(i);
       }
        return result;
    }

    vector<int> prevSmaller(vector<int>&A)
    {
       vector<int> result(A.size());
       stack<int> s;

       for(int i = 0;i<A.size();i++)
       {

           while(!s.empty() and A[s.top()]>=A[i])
                s.pop();
            if(!s.empty())
                result[i] = s.top();
            else
                result[i] = -1;
            s.push(i);
       }
        return result;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        vector<vector<int>> A(matrix.size(),vector<int>(matrix[0].size(),0));
        int maxi = 0;
        for(int i = 0;i<A.size();i++)
        {
            for(int j = 0;j<A[i].size() ;j++)
            { 
                if(i>0 and matrix[i][j]=='1')
                    A[i][j] = 1+A[i-1][j];
                if(i==0 and matrix[i][j]=='1')
                    A[i][j] = 1;
            }
            vector<int> prev = prevSmaller(A[i]);

            vector<int> next = nextSmaller(A[i]);

            for(int j = 0;j<A[i].size();j++)
                maxi = max(maxi,(next[j]-prev[j]-1)*A[i][j]);
        }
        return maxi;
    }
};