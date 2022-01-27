class Solution {
public:
    int minSteps(int n)
    {
        int d = 2;
        int ans = 0;
        while(n>1)
        {
            while(n%d==0)
            {
                n=n/d;
                ans+=d;
            }
            d++;
        }
       return ans; 
    }
};