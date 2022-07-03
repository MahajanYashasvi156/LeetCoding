class Solution 
{
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
    {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(),horizontalCuts.end());
    sort(verticalCuts.begin(),verticalCuts.end());
        
        int height = 0;
        for(int i = 1;i<horizontalCuts.size();i++)
        {
            height = max(height,horizontalCuts[i]-horizontalCuts[i-1]);
        }
        
        int width = 0;
        
        for(int i = 1;i<verticalCuts.size();i++)
        {
            width = max(width,verticalCuts[i]-verticalCuts[i-1]);
        }
        
        return (long(height)*width)%1000000007;
    }
};