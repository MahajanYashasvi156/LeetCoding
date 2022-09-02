class Solution {
public:
    int maxDistToClosest(vector<int>& seats)
    {
        int left = -1;
        int n = seats.size()-1;
        int maxDistance = INT_MIN;
        
        for(int i = 0;i<=n;i++)
        {
            if(seats[i]==0)
                continue;
            
            if(left==-1)
            {
                maxDistance = max(maxDistance,i);
            }
            else
            {
                maxDistance = max(maxDistance,(i-left)/2);
            }
            
            left = i;
        }
        
        if(seats[n]==0)
            maxDistance = max(maxDistance,n-left);
        
        return maxDistance;
    }
};