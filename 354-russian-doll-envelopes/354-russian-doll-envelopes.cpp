/*
LIS application

TC - O(NlogN)
SC - O(N)

Using Binary search + DP for LIS from striver
For equal widths, twick sort function to work incorrectly
*/
class Solution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        vector<int> heightLIS;
        
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b)
             {
                 if (a[0] < b[0])
                     return true;
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return false;
             });
        
        heightLIS.push_back(envelopes[0][1]);
        
        for(int i=1;i<n;i++)
        {
            int index = lower_bound(heightLIS.begin(),heightLIS.end(),envelopes[i][1]) - heightLIS.begin();
            if(index == heightLIS.size())
            {
                heightLIS.push_back(envelopes[i][1]);
            }
            
            else
                heightLIS[index] = envelopes[i][1];
        }
        
        return heightLIS.size();
    }
};


/*
Just a LIS application
TC - O(N^2)
SC - O(N)

TLE
*/

/*

class Solution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        vector<int> heightLIS(n);
        sort(envelopes.begin(),envelopes.end());
        
        int maxEnvelope = 1;
        heightLIS[0]=1;
        for(int i=1;i<n;i++)
        {
            int maxcount = 0;
            for(int j=0;j<i;j++)
            {
                if(envelopes[i][0]!=envelopes[j][0] and envelopes[i][1]>envelopes[j][1])
                    maxcount = max(maxcount,heightLIS[j]);
            }
            heightLIS[i] = maxcount+1;
            maxEnvelope =max(heightLIS[i],maxEnvelope);
        }
        return maxEnvelope;
    }
};
*/
