class Solution 
{
    int bfs(unordered_map<int,vector<int>>&graph,vector<int>&arr )
    {
        int n = arr.size();
        vector<int>visited(n);    
        queue<int> q;
        q.push(0);
        visited[0] = 1;    
        int steps = 0;
        
        while(!q.empty())
        {
            int s = q.size();
            
            for(int i = 0;i<s;i++)
            {
                int currIndex = q.front();
                q.pop();
                if(currIndex==n-1)
                    return steps;
                for(int jump : graph[arr[currIndex]])
                {
                    if(visited[jump]==0)
                    {
                        visited[jump] = 1;
                        q.push(jump);
                    }
                }
                graph.erase(arr[currIndex]);
                if(currIndex+1<n and visited[currIndex+1]==0)
                {
                    visited[currIndex+1] = 1;
                    q.push(currIndex+1);
                }
                if(currIndex-1>=0 and visited[currIndex-1]==0)
                {
                    visited[currIndex-1] = 1;
                    q.push(currIndex-1);
                }
            }
            steps++;
        }
        return steps;
    }
public:
    int minJumps(vector<int>& arr) 
    {
        
        unordered_map<int,vector<int>> graph;
        
        for(int i = 0;i<arr.size();i++)
        {
            graph[arr[i]].push_back(i);
        }
        
        return bfs(graph,arr);
    }
};