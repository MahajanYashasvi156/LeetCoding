/*
Link - https://leetcode.com/problems/coin-change/submissions/

TC - O(n*amount) //n is the number of coins.
SC - O(amount)

Approach - slight variation of coin change combination problem(Here no need of coin change permuatation as we just need minimum coins - 225 is same as 252)

1. Starage and meaning - 1D Table of size = amount+1.
   ith cell of DP means the minimum number of coins of getting i amount of money with the coins considered till now.
   
2. Direction - small problem is minimum number of coins of getting 0 amount of money - we need zero coins to form 0 amount of money.
    Large problem is minimum number of coins of getting required amount of money.

3. Travel and solve - Consider one coin at each time. Traverse from 0 to amount. After each iteration dp state represents the minimum number of coins required considering all coins till now.

Conclusion Points - 
1. For Combination - cycle.
2. For permutation - explore each possiblities at each cell.
3. If Duplicates allowed - one dimension DP (Combination and Permuation Coin change).
4. If Duplicates not allowes - two dimension DP required (Target Subset Sum).
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1,-1);
        
        dp[0]=0;
        
        for(int coin:coins)
        {
            for(int i=coin;i<=amount;i++)
            {
                if(dp[i-coin]!=-1 and dp[i]!=-1)
                    dp[i]=min(dp[i],dp[i-coin]+1);
                
                else if(dp[i-coin]!=-1)
                    dp[i]=dp[i-coin]+1;
            }
        }
        return dp[amount];
    }
};