class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sumTillNow = 0;
        int maxSum = INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            sumTillNow +=nums[i];
            maxSum = max(maxSum,sumTillNow);
            if(sumTillNow<0)
                sumTillNow = 0;
        }
        return maxSum;
    }
};