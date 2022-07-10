class Solution
{
public:
    int maxResult(vector<int>& nums, int k) 
    {
        int maxi = INT_MIN;
        priority_queue<pair<int,int>> maxHeap;
        maxHeap.push({nums[nums.size()-1],nums.size()-1});
        int scoreTillNow = 0;
        
        for(int i = nums.size()-2;i>=0;i--)
        {
            while(maxHeap.top().second>i+k)
                maxHeap.pop();
            scoreTillNow = maxHeap.top().first;
            maxHeap.push({nums[i]+scoreTillNow,i});
        }
        return nums[0]+scoreTillNow;
    }
};