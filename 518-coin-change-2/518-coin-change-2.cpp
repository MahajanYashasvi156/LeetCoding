/*
Link - https://leetcode.com/problems/coin-change-2/submissions/

TC - 
SC - 

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

class Solution 
{   
public:
    int change(int amount, vector<int>& coins) 
    { 
        vector<int> dp(amount+1,0);
        
        dp[0]=1;
        for(int i=0;i<coins.size();i++)
        {
            for(int j=coins[i];j<=amount;j++)
            {
                    dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};
