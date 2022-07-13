class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) 
    {
        int n = points.size();
        int m = rectangles.size();
        vector<int> result(n,0);
        
        vector<vector<int>> possibleHeight(101);
        
        for(auto r:rectangles)
            possibleHeight[r[1]].push_back(r[0]);

        for(int i = 0;i<possibleHeight.size();i++)
            sort(possibleHeight[i].begin(),possibleHeight[i].end());
    
        for(int i = 0;i<n;i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int count = 0;
            for(int j = y;j<=100;j++)
            {
                if(possibleHeight[j].size())
                {
                    count += possibleHeight[j].size()-(lower_bound(possibleHeight[j].begin(),possibleHeight[j].end(),x)-possibleHeight[j].begin());
                }
            }
            result[i] = count;
        }
        return result;
        
    }
};