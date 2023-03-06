/*
TC - O(N)
SC - O(N)
*/
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
// To prevent stepping back. Means if there are same values then we will directly go to the index which is most optimal to us. 0 0 0 0 _____ from first 0 we will directly go the 0 which will give most optimal result to us. Then there is no need to go to 0->2->3 (index positions) we can directly go to 0->3.
                
// Cases - 0_ 4 5 0 6 1_ 3_ 2 10 1_ 0_ 7 8 9 3 jumps would be - 0->0->1->1->3->3 = 5 jumps here we can see that once we get higher index we can also jump to lower index in both case when arr[i]==arr[j] and when arr[i]!=arr[j]
                
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