class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        vector<vector<int>> ans;
        
        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>> maxHeap;
        
        for(int i=0;i<points.size();i++)
        {
            int distance = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            
            
            
            if(maxHeap.size()<k)
            {
                 maxHeap.push({distance,{points[i][0],points[i][1]}});
            }
            else if(maxHeap.top().first>distance)
            {
                maxHeap.pop();
                maxHeap.push({distance,{points[i][0],points[i][1]}});
            }
            
            
        }
        
        while(maxHeap.empty()==false)
        {
            ans.push_back({maxHeap.top().second.first,maxHeap.top().second.second});
            maxHeap.pop();
        }
        return ans;
    }
};