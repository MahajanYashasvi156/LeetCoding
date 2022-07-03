class Solution 
{
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) 
    {
        priority_queue<pair<int,int>> maxheap;
        
        for(auto a:boxTypes)
            maxheap.push({a[1],a[0]});
        int maxi = 0;
        while(truckSize>0 and !maxheap.empty())
        {
            int s = min(truckSize,maxheap.top().second);
            maxi +=s*maxheap.top().first;
            maxheap.pop();
            truckSize-=s;
        }
        return maxi;
    }
};