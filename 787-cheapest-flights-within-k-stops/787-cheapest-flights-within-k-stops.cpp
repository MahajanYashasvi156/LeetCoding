/*
Dijisktra Algorithm - 

Here there are two factors to decide the shortest path 
1. Cost should be minimum
2. If at any node we are reaching with lesser level then the chances of reaching to the destination increases because it may possible that cost to reach at current cell is high but it may be lead to us ans. 

*/
typedef pair<int,pair<int,int>> p;//cost, dest,level
class Solution 
{
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k)
    {
        vector<vector<pair<int,int>>> adj(n);
        priority_queue<p,vector<p>,greater<p>> minHeap;
        //distance + level
        vector<pair<int,int>> distance(n,{INT_MAX,INT_MAX});
        for(auto a: flights)
        {
            int start = a[0];
            int dest = a[1];
            int price = a[2];
            adj[start].push_back({dest,price});
        }
        
        minHeap.push({0,{src,0}});
        distance[src]={0,0};
        
        while(!minHeap.empty())
        {
            int weight = minHeap.top().first;
            int start = minHeap.top().second.first;
            int level = minHeap.top().second.second;
            minHeap.pop();
                  
            if(start==dst)
                return weight;
            for(auto a:adj[start])
            {
                int dest = a.first;
                int price = a.second;
                
                //If we have atleast one more stop left then we can directly move to next stop without knowing whther it is destination or not. But if we have no more stops left the next move must be at destination only.
                if(level==k and dest==dst or level<k)
                {
                    if(distance[dest].first>weight+price or distance[dest].second>level+1)
                    {
                        distance[dest].first=weight+price;
                        distance[dest].second = level+1;
                        minHeap.push({distance[dest].first,{dest,level+1}});
                    }     
                }
            }
        }
        return -1;
    }
};