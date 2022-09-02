/*
    Intution - Pick the element which is the largest till now i.e. maxi. Now the correct possition of this maxi is at index = maxi. So we the chunk size should be atleast from the original incorrect position of maxi to the correct position of maxi. 
    
    If in between some other elemnt greatr than maxi appears then we have to expand our chunk size so the current maxi will be at its correct position.
    
*/
class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr)
    {
        int maxi = INT_MIN;
        int ans = 0;
        for(int i = 0;i<arr.size();i++)
        {
            maxi = max(maxi,arr[i]);
            if(maxi==i)
                ans++;
        }
        return ans;
    }
};


/*
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
*/