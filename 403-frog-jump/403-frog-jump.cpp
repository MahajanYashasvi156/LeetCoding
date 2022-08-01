/*

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
            if(s==0 and reachedWithJumps.find(1)!=reachedWithJumps.end())
            {
                reachedWithJumps[1].insert(1);
            }
            if(s!=0)
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
            
        }
    
        if(reachedWithJumps[stones[stones.size()-1]].size())
            return true;
        
        return false;
        
    }
};