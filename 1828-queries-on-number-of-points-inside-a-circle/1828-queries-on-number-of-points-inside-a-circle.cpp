class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) 
    {
       vector<int> result(queries.size(),0);
        
        for(int i = 0;i<queries.size();i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int r = queries[i][2];
            
            for(int j = 0;j<points.size();j++)
            {
                int m = points[j][0];
                int n = points[j][1];
                
                int euclideanDistance = (m-x)*(m-x)+(n-y)*(n-y);
                
                if(euclideanDistance<=r*r)
                {
                    result[i]++;
                }
            }
        }
        return result;
    }
};