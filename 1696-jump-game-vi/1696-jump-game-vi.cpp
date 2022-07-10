class Solution
{
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int n = nums.size();
        priority_queue<pair<int,int>> maxHeap;
        maxHeap.push({nums[n-1],n-1});
        int scoreTillNow = nums[n-1];
        
        for(int i = n-2;i>=0;i--)
        {
            scoreTillNow = nums[i];
            while(maxHeap.top().second>i+k)
                maxHeap.pop();
            scoreTillNow += maxHeap.top().first;
            maxHeap.push({scoreTillNow,i});
        }
        
        return scoreTillNow;
    }
};