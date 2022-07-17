class Solution 
{
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) 
    {
        unordered_map<int,vector<int>> neighbours;
        
        for(auto a: adjacentPairs)
        {
            neighbours[a[0]].push_back(a[1]);
            neighbours[a[1]].push_back(a[0]);
        }
        
        vector<int> result;
        int prev;
        int curr;
        
        for(auto n : neighbours)
        {
            if(n.second.size()==1)
            {
                result.push_back(n.first);
                result.push_back(n.second[0]);
                prev = result[0];
                curr = result[1];
                break;
            }
        }
        
        while(neighbours[curr].size()>1)
        {
            if(neighbours[curr][0]!=prev)
            {
                result.push_back(neighbours[curr][0]);
                prev = curr;
                curr = neighbours[curr][0];
            }
            else
            {
                result.push_back(neighbours[curr][1]);
                prev = curr;
                curr = neighbours[curr][1];
            }
        }
        return result;
    }
};