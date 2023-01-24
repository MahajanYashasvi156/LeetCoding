class Solution 
{
public:
 /*   int snakesAndLadders(vector<vector<int>>& board) 
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
                cout<<curr<<" ";
                if(curr==n*n)
                    return step;
                
                for(int i = curr+1;i<=min(curr+6,n*n);i++)
                {
                    int r = n-1-i/n;
                    int c = i%n;
                    
                    if(r%2==0)
                        c=n-1-c;
                    cout<<r<<" "<<c<<endl;
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
    */
    
    vector<int> findcordinates(int pos,int n){
          vector<int>temp;
            int r=n-(pos-1)/n-1;
            int c=(pos-1)%n;
            if(r%2==n%2){
                return temp={r,n-1-c};
            }else{
                return temp={r,c};
            }
            }


    int snakesAndLadders(vector<vector<int>>& board) {
        int n= board.size();
        queue<int>q;
        vector<vector<bool>>visited( n , vector<bool>(n, false)); 
        int ans=0;
        q.push(1);
        visited[n-1][0]=true;
        while(!q.empty()){
            int size=q.size();
           
            for(int i=0;i<size;++i){
                int front=q.front();
                q.pop();
                if(front==n*n) return ans;
                for(int k=1;k<=6;++k){
                    if(k+front>n*n) break;
                    vector<int>pos=findcordinates(front+k,n);
                    int r=pos[0];
                    int c=pos[1];
                    if(visited[r][c]==true) continue;
                    visited[r][c]=true;
                    if(board[r][c]!=-1){
                        q.push(board[r][c]);
                    }else{
                        q.push(front+k);
                    }

                }
            }
            ans++;
        }
        return -1;
    }
};