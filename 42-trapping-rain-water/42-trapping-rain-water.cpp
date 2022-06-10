class Solution {
public:
    int trap(vector<int>& A) 
    {
        vector<int> leftMax(A.size(),INT_MIN);
        for(int i = 1;i<A.size();i++)
            leftMax[i] = max(leftMax[i-1],A[i-1]);

        int rightMax = A[A.size()-1];
        int trappedWater = 0;
        for(int i = A.size()-2;i>=0;i--)
        {
            int height = min(leftMax[i],rightMax);
            if(height>A[i])
                trappedWater+=(height-A[i]);
            rightMax = max(rightMax,A[i]);
        }
        return trappedWater;
    }
};

/*
class Solution 
{
public:
    int trap(vector<int>& height)
    {
        int size=height.size();
        vector<int> rightMax(size);
        vector<int> leftMax;
        int trappedWater=0;
        //First height has not any maximum height.
        leftMax.push_back(0);
        //Left max stores the maximum height before current height excluding current height.
        for(int i=1;i<size;i++)
        {
            leftMax.push_back(max(height[i-1],leftMax[i-1]));
        }
        //Last height has not any maximum height.
        rightMax[size-1]=INT_MIN;
         //right max stores the maximum after current height excluding current height.
        for(int i=height.size()-2;i>=0;i--)
        {
            rightMax[i]=max(height[i+1],rightMax[i+1]);
        }
        
        for(int i=0;i<height.size();i++)
        {
        //if the minimum of rightmax and left max is greater than current height then only it can trap water.Subtract that height from the current height to get the trapped water.
            if(min(rightMax[i],leftMax[i])>height[i])
                trappedWater=trappedWater+min(rightMax[i],leftMax[i])-height[i];
        }
        return trappedWater;
    }
};
*/