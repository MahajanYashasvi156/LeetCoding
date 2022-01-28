class Solution 
{
public:
    int maxEnvelopes(vector<vector<int>>& envelopes)
    {
        int n = envelopes.size();
        vector<int> heightLIS;
        
        //sort(envelopes.begin(),envelopes.end());
         sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] >= b[1]);
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