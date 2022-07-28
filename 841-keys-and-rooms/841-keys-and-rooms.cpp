class Solution 
{
    void dfs(vector<vector<int>>&rooms,int src,vector<int>&visited)
    {
        visited[src] = 1;
        
        for(int key : rooms[src])
        {
            if(visited[key] == 0)
            {
                dfs(rooms,key,visited);
            }
        }
    }
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        int n = rooms.size();
        
        vector<int> visited(n,0);
        
        dfs(rooms,0,visited);
        
        for(int val:visited)
        {
            if(val==0)
                return false;
        }
        return true;
    }
};