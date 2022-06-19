class Solution 
{
public:
    int maxPoints(vector<vector<int>>& A) 
    {
        if(A.size()==0)
            return 0;
        
        int maxPoints = 0;

        for(int i = 0;i<A.size()-maxPoints-1;i++)
        {
            unordered_map<double,int> m; 
            for(int j = i+1;j<A.size();j++)
            {
                double slope =INT_MAX;
                if(A[j][0]!=A[i][0])
                    slope = (double)(A[j][1]-A[i][1])/(A[j][0]-A[i][0]);
                m[slope]++;
                maxPoints = max(maxPoints,m[slope]);
            }
        }
        return maxPoints+1;
    }
};