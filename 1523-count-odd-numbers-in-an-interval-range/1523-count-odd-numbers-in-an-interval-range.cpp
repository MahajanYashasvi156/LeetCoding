class Solution {
public:
    int countOdds(int low, int high) 
    {
        if(low%2==0)
        {
            low++;
        }
        if(low>high)
            return 0;
        
        int ans = ceil((high-low+1)/2.0);
      
        return ans;
        
        
    }
};