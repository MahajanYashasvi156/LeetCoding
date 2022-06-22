class Solution 
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int,vector<int>,greater<int>> minheap;
        for(int i = 1;i<heights.size();i++)
        {
            if(heights[i]<=heights[i-1]) continue;
            int diff = heights[i] - heights[i-1];
            if(minheap.size()<ladders)
            {
                minheap.push(diff);
            }
            else
            {
                if(!minheap.empty() and minheap.top()<diff)
                {
                    bricks = bricks-minheap.top();
                    minheap.pop();
                    minheap.push(diff);
                }
                else
                {
                    bricks = bricks-diff;
                }
                if(bricks<0)
                {
                    return i-1;
                }
            }
        }
        return heights.size()-1;
    }
};