class Solution 
{
public:
     int MCM(vector<int>&arr,vector<vector<int>>&dp,int l,int r,vector<vector<int>>&maxVal)
     {
         if(l>=r)
             return 0;
         
         if(dp[l][r]!=-1)
             return dp[l][r];
         
         long ans = INT_MAX;
         for(int p = l;p<r;p++)
         {
            long currSum = maxVal[l][p]*maxVal[p+1][r]+MCM(arr,dp,l,p,maxVal) +MCM(arr,dp,p+1,r,maxVal);
            ans = min(ans,currSum);
         }
         
         return dp[l][r] = ans;
     }
    int mctFromLeafValues(vector<int>& arr) 
    {
        vector<vector<int>> maxVal(arr.size(),vector<int>(arr.size(),INT_MIN));
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        
        for(int i = 0;i<arr.size();i++)
        {
            int maxi = INT_MIN;
            
            for(int j = i;j<arr.size();j++)
            {
                maxi = max(maxi,arr[j]);
                maxVal[i][j] = maxi;
            }
        }
        
        return MCM(arr,dp,0,arr.size()-1,maxVal);
    }
};