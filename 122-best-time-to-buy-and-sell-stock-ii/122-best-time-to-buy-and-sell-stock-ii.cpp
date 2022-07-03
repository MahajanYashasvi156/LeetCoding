/*
Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/
TC - O(n)
SC - O(1)

Sum of all profits achievable following sequence : BSBSBSBS...
*/

class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        int maxProfit =0;
        int buy=0;
        int sell=0;
        
        for(int i=1;i<n;i++)
        {
            if(prices[i]>=prices[i-1])
                sell++;
            else
            {
                maxProfit+=(prices[sell]-prices[buy]);
                sell=i;
                buy=i;
            }
        }
        maxProfit+=(prices[sell]-prices[buy]);
        return maxProfit;
    }
};

/*
class Solution 
{
public:
    int maxProfit(vector<int>& A) 
    {
        if(A.size()==1)
            return 0;
        int buy =-1;
        int sell = -1;
        int profit = 0;
        for(int i = 0;i<A.size()-1;i++)
        {
            if(A[i]>A[i+1] and buy!=-1)
            {
                sell = A[i];
                profit+=(sell-buy);
                buy=-1;
            }
            else if(buy==-1 and A[i]<A[i+1])
                buy = A[i];
        }
        if(buy!=-1)
            profit+=A[A.size()-1]-buy;

        return profit;
    }
};
*/
/*
class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        for(int i = 1;i<prices.size();i++)
        {
            if(prices[i]-prices[i-1]>0)
            {
                profit+=(prices[i]-prices[i-1]);
            }
        }
        return profit;
    }
};*/