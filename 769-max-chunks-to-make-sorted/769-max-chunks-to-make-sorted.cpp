class Solution 
{
    //https://leetcode.com/problems/max-chunks-to-make-sorted/discuss/595709/Monotonic-stack-solution-with-detailed-explanation
    
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> s;
    
        for(int i = 0;i<arr.size();i++)
        {
            int largestINChunck = INT_MIN;
            while(s.empty()==false and s.top()>arr[i])
            {
                if(largestINChunck==INT_MIN)
                    largestINChunck = s.top();
                s.pop();
            }
            s.push(max(arr[i],largestINChunck));
        }        
        return s.size();
    }
};