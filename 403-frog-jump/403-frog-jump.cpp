/*
TC - O(stones.size())
SC - O(stones.size())

for each stones , store the last jump needed to reach at that stone.

*/
class Solution 
{
public:
    bool canCross(vector<int>& stones) 
    {
        unordered_map<int,set<int>> reachedWithJumps;
        
        for(int s : stones)
        {
            reachedWithJumps[s] = {};
        }
        
        reachedWithJumps[0].insert(0);
    
        for(int s : stones)
        {
            for(int j : reachedWithJumps[s])
            {
                if(reachedWithJumps.find(s+j+1)!=reachedWithJumps.end())
                {
                    reachedWithJumps[s+j+1].insert(j+1);
                }
                if(reachedWithJumps.find(s+j)!=reachedWithJumps.end())
                {
                    reachedWithJumps[s+j].insert(j);
                }
                if(j-1>0 and reachedWithJumps.find(s+j-1)!=reachedWithJumps.end())
                {
                    reachedWithJumps[s+j-1].insert(j-1);
                }
            }
        }
    
        if(reachedWithJumps[stones[stones.size()-1]].size())
            return true;
        
        return false;
        
    }
};