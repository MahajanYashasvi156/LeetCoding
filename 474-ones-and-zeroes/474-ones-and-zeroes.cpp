class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        
        for(int i = 1;i<=strs.size();i++)
        {
            int ones = 0;
            int zeroes = 0;
            
            for(char c : strs[i-1])
            {
                if(c=='1')
                    ones++;
                else
                    zeroes++;
            }
            
            for(int x = 0;x<=m;x++)
            {
                for(int y = 0;y<=n;y++)
                {
                    if(x>=zeroes and y>=ones)
                        dp[i][x][y] = max(dp[i-1][x][y],dp[i-1][x-zeroes][y-ones]+1);
                    else
                        dp[i][x][y] = dp[i-1][x][y];
                    //cout<<dp[i][x][y]<<" ";
                }
                //cout<<endl;
            }
            
        }
        return dp[strs.size()][m][n];
    }
};