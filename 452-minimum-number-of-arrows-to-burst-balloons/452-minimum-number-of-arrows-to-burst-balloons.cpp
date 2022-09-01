class Solution
{
    static bool cmp(vector<int>&a,vector<int>&b)
    {
        return a[1]<b[1];
    }
        
public:
    int findMinArrowShots(vector<vector<int>>& points) 
    {
        /*
        
            TC - [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]
            
            Logic :- We can shot the ballons in once arrow if that will have atleast one point in common.
            
            Sort on the basis of end of the ballon. If there exist any ballon whose end point is after current ballon and its start points is before the end of current point. then they will surely have an overlapping case.
              ___
            _______
        ________________       
        
        All three can be shot in one arrow only.
        */
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