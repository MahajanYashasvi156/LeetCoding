/*class Solution 
{
    int M = 1000000007;
    int solve(int startPos , int endPos, unordered_map<int,unordered_map<int,int>> &dp,int k)
    {
        if(k==0)
            return startPos==endPos;
        
        if(dp[startPos].find(k)!=dp[startPos].end())
            return dp[startPos][k];
        int forward = solve(startPos+1,endPos,dp,k-1);
        int backward = solve(startPos-1,endPos,dp,k-1);
        
        return dp[startPos][k] = (forward + backward)%M;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) 
    {
        unordered_map<int,unordered_map<int,int>> dp;
        
        return solve(startPos,endPos,dp,k);
    }
};
*/

class Solution 
{
    int M = 1000000007;
    int solve(int startPos , int endPos,vector<vector<int>> &dp
,int k)
    {
        if(k==0)
            return startPos==endPos;
        
        if(dp[startPos][k]!=-1)
            return dp[startPos][k];
        int forward = solve(startPos+1,endPos,dp,k-1);
        int backward = solve(startPos-1,endPos,dp,k-1);
        
        return dp[startPos][k] = (forward + backward)%M;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) 
    {
        int newStartPos = k;
        int newEndPos = newStartPos + (endPos-startPos);
        vector<vector<int>> dp(2*k+1,vector<int>(k+1,-1));
        return solve(newStartPos,newEndPos,dp,k);
    }
};