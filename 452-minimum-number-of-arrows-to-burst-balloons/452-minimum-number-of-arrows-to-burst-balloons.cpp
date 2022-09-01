class Solution
{
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
        
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        sort(points.begin(),points.end(),cmp);
        
        int ans = 0;
        
        for(int i = 0;i<points.size();)
        {
            int end = points[i][1];
            
            while(i<points.size() and points[i][0]<=end)
                i++;
            
            ans++;
        }
        return ans;
    }
};