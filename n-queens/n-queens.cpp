class Solution 
{
public:
    bool isSafe(vector<string>&board,int row,int col,int n,vector<bool>&queenRow)
    {
        //Row Check
        if(queenRow[row])
            return false;
        
        //Upper Diagonal Check 
        for(int i=row,j=col;i>=0 && j>=0;i--,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        
        //Lower Diagonal Check 
        for(int i=row,j=col;i<n && j>=0;i++,j--)
        {
            if(board[i][j]=='Q')
                return false;
        }
        return true;
    }
    
    void check(int n,vector<string>&board,vector<vector<string>> &result,int  &col,vector<bool>&queenRow)
    {
        if(col==n)
        {
            result.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n,queenRow))
            {
                board[row][col]='Q';
                queenRow[row]=true;
                col++;
                check(n,board,result,col,queenRow);
                col--;
                board[row][col]='.';
                queenRow[row]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        string s(n,'.');
        vector<string> board(n,s);
        vector<bool> queenRow(n,false);
        int col=0;
        check(n,board,result,col,queenRow);
        return result;
    }
};