class Solution 
{
public:
    int totalHammingDistance(vector<int>& A) 
    {
        long int  ans = 0;
        for(int i = 0;i<32;i++)
        {
            int ones = 0;
            int zeroes = 0;
            for(int j = 0;j<A.size();j++)
            {
                if(A[j] & 1<<i)
                    ones++;
                else 
                    zeroes++;

            }
            ans += ones*long(zeroes);
        }
        return ans%1000000007;
    }
};