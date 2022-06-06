class Solution 
{
public:
    int maxArea(vector<int>& height)
    {
        int area = 0;
        int i = 0;
        int j = height.size()-1;
        while(i<j)
        {
            int containerHeight = min(height[i],height[j]);
            int containerWidth = j-i;
            area = max(area,containerHeight*containerWidth);
            if(height[i]==containerHeight)
                i++;
            else
                j--;
                
        }
        return area;
    }
};