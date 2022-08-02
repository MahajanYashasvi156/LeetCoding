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
        
        reachedWithJumps[0].insert(0);
    
        for(int s : stones)
        {
            if(reachedWithJumps.find(s)!=reachedWithJumps.end())
            {
                for(int jumps : reachedWithJumps[s])
                {
                    for(int var=-1;var<=1;var++)
                    {
                        if(jumps+var>0)
                            reachedWithJumps[s+jumps+var].insert(jumps+var);
                    }
                }
            }
        }
    
        return reachedWithJumps[stones[stones.size()-1]].size();
        
    }
};