class Solution 
{
public:
    int numRabbits(vector<int>& answers) 
    {
        unordered_map<int,int> freq;
        
        int ans = 0;
        for(int a : answers)
        {
            freq[a]++;
            if(freq[a]>a+1)
            {
                freq[a] = 1;
            }
            if(freq[a]==1)
            {
                ans = ans+a+1;
            }
            
        }
        
        return ans;
    }
};