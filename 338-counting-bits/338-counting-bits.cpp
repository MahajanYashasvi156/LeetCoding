class Solution 
{
public:
    vector<int> countBits(int n) 
    {
        vector<int> result(n+1);
        int i = 0;
        while(i<=n)
        {
            if(i==0 or i==1)
            {
                result[i]=i;
            }
            else
            {
                int halfindex = i/2;
                result[i]=result[halfindex] + i%2;
            }
            i++;
        }
        return result;
    }
};