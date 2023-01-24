class Solution 
{
public:
  int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = board.size();
        vector<int>visited(n*n+1,0);
        int step = 0;
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        
        while(!q.empty())    
        {
            int s = q.size();
            while(s--)
            {
                int curr = q.front();
                q.pop();
               
                if(curr==n*n)
                    return step;
                
                for(int i = curr+1;i<=min(curr+6,n*n);i++)
                {
                    int r = n-1-(i-1)/n;
                    int c = (i-1)%n;
                    
                    if((n-r-1)%2)
                        c=n-1-c;
                   
                    if(board[r][c]==-1 and visited[i]==0)
                    {
                        visited[i]=1;
                        q.push(i);
                    }
                    
                    else if(board[r][c]!=-1 and visited[board[r][c]]==0)
                    {
                        visited[board[r][c]] = 1;
                        q.push(board[r][c]);
                    }  
                }
            }
            step++;
        }
        return -1;
    }
   
    
};
