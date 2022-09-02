/*
    Find the max from left including itself and minimum from right.
    
    if the maxi from left is smaller or equal to mini from right that means there is no element after current which is greater than current element. So there is no need to expand the chunk. We can end the current chunk at current position and start new chunk from the next position.
    
    
*/
class Solution 
{
public:
    int maxChunksToSorted(vector<int>& arr) 
    {
        vector<int>leftMax(arr.size(),INT_MIN);
        vector<int>rightMin(arr.size()+1,INT_MAX);
        
        leftMax[0] = arr[0];
        for(int i = 1;i<arr.size();i++)
        {
            leftMax[i] = max(leftMax[i-1],arr[i]);
        }
        
        for(int i = arr.size()-1;i>=0;i--)
        {
            rightMin[i] = min(rightMin[i+1],arr[i]);
        }
        int chunks = 0;
        
        for(int i = 0;i<arr.size();i++)
        {
            if(leftMax[i]<=rightMin[i+1])
               chunks++;
        }
        return chunks;
    }
};