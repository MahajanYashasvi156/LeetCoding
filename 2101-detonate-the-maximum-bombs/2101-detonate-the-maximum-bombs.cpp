class Solution 
{
public:
    int maximumDetonation(vector<vector<int>>& bombs) 
    {
        int ans = 0;
        for(int i = 0;i<bombs.size();i++)
        {
            queue<pair<int,pair<int,int>>>q;
            vector<int> detonated(bombs.size(),0);
            q.push({bombs[i][2],{bombs[i][0],bombs[i][1]}});
            detonated[i] = 1;
            int count = 0;
            
            while(!q.empty())
            {
                int r = q.front().first;
                int x = q.front().second.first;
                int y = q.front().second.second;
                q.pop();
                count++;
                for(int j = 0;j<bombs.size();j++)
                {
                    if(detonated[j]==0)
                    {
                        
                        //Distance between two bombs. if it is less than the detonated bomb then neighbour bomb will also be detonated.
                        long int distance = long(x-bombs[j][0])*(x-bombs[j][0])+long(y-bombs[j][1])*(y-bombs[j][1]);
                        if(distance<=long(r)*r)
                        {
                            detonated[j] = 1;
                            q.push({bombs[j][2],{bombs[j][0],bombs[j][1]}});
                        }
                    }
                }
            }
            ans = max(ans , count);
        }
        return ans;
    }
};