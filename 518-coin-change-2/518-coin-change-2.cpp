/*
Link - https://leetcode.com/problems/coin-change-2/submissions/

TC - O(2^coins)
ASC - O(coins)
SC - O(1)

class Solution 
{
    int recursive(int index,int amount, vector<int>& coins)
    {
        if(amount==0)
            return 1;

        if(amount<0 or index==coins.size())
            return 0;
        
        return recursive(index,amount-coins[index],coins) + recursive(index+1,amount,coins);
    }
    
public:
    int change(int amount, vector<int>& coins) 
    { 
        return recursive(0,amount,coins);
    }
};
*/

/*
Iterative DP - 

TC - O(amount*coins)
SC - O(amount)

1. Starage and meaning - 1D Table of size = amount+1.
   ith cell of DP means the number of ways of getting i amount of money with the coins considered till now.
   
2. Direction - small problem is number of ways of getting 0 amount of money - there will be always one way pick no coins.
    Large problem is getting required amount of money.

3. Travel and solve - Traverse from 0 to amount. Consider one coin at each time. After each iteration dp state represents the number of ways considering all coins till now.

Here, The problem is of finding combination and not of permutations i.e. either 2 5 or 5 2 can be considered for amount 7 bt not both. This is ensured by our loop - it will always first pick the coin which appears first in the coins array.
*/
class Solution 
{   
public:
    int change(int amount, vector<int>& coins) 
    { 
        vector<int> dp(amount+1,0);
        
        dp[0]=1;
        for(int coin : coins)
        {
            for(int j=coin;j<=amount;j++)
            {
                    dp[j]+=dp[j-coin];
            }
        }
        return dp[amount];
    }
};
