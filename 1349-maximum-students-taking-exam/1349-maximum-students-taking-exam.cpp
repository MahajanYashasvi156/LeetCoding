class Solution
{
    int solve(vector<vector<char>>& seats,int r, int prevRowMask,vector<vector<int>>&dp)
    {
        int row = seats.size();
        int col = seats[0].size();
        
        if(r==row)
            return 0;
        if(dp[r][prevRowMask]!=-1)
            return dp[r][prevRowMask];
        
        int ans = 0;
        
        for(int mask = 0;mask<(1<<col);mask++)
        {
            int count = 0;
            int currRowMask = 0;
            
            for(int c = 0;c<col;c++)
            {
                if(seats[r][c]=='.' and (mask & 1<<c))
                {
                    bool ul = c>0?(prevRowMask & 1<<(c-1)) : false; 
                    bool ur = c<col-1?(prevRowMask & 1<<(c+1)) : false;
                    bool l = c>0?(currRowMask & 1<<(c-1)) : false; 
                    bool r = c<col-1?(currRowMask & 1<<(c+1)) : false;
                    if(ul==false and ur==false and l==false and r==false)
                    {
                        count++;
                        currRowMask = currRowMask | 1<<c;
                    }
                }
            }
            ans = max(ans,count+solve(seats,r+1,currRowMask,dp));
        }
        return dp[r][prevRowMask] = ans;
    }
public:
    int maxStudents(vector<vector<char>>& seats) 
    {
        int row = seats.size();
        int col = seats[0].size();
        
        vector<vector<int>> dp(8,vector<int>(1<<8,-1));
        
        return solve(seats,0,0,dp);
    }
};