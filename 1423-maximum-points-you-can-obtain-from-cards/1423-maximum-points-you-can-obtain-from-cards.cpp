/*
TC - O(N)
SC - O(1)

Concept - Sliding Window of Size B
*/
class Solution {
public:
    int maxScore(vector<int>& A, int B) 
    {
        int ws = 0;
        int result = INT_MIN;
        for(int i=0;i<B;i++)
        {
            ws += A[i];
        }
        result = max(result,ws); 
        int i = B-1;
        int j = A.size()-1;
        while(i>=0)
        {
            ws = ws - A[i--] + A[j--];
            result = max(result,ws); 
        }
        return result;
    }
};