class Solution 
{
public:
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int low = *max_element(weights.begin(),weights.end());
        
        int high = INT_MAX;
        int ans = INT_MAX;
        while(low<=high)
        {
            int capacity = low +(high-low)/2;
        
            int sum = 0;
            int currdays = 1;
            
            for(int i = 0;i<weights.size();i++)
            {
                if(sum+weights[i]<=capacity)
                    sum = sum + weights[i];
                else
                {
                    sum = weights[i];
                    currdays++;
                }
            }
            
            if(currdays>days)
                low = capacity+1;
            else
            {
                ans = capacity;
                high = capacity-1;
            }
        }
        return ans;
    }
};