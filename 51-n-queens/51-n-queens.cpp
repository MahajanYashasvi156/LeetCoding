
/*


Link - https://leetcode.com/problems/n-queens/submissions/

TC - O(N! * N)
SC - O(N^2)
Aux SC - O(N)


class Solution 
{
public:
    bool isSafe(vector<string>&board,int row,int col,int n)
    {
        //Row Check
        for(int i=0;i<col;i++)
        {
             if(board[row][i]=='Q')
                return false;
        }
        
        
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
    
    void check(int n,vector<string>&board,vector<vector<string>> &result,int col)
    {
        if(col==n)
        {
            result.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(isSafe(board,row,col,n))
            {
                board[row][col]='Q';
                
                check(n,board,result,col+1);
                
                board[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        
        string s(n,'.');
        vector<string> board(n,s);
      
        int col=0;
        
        check(n,board,result,col);
        
        return result;
    }
};
*/

/*
Link - https://leetcode.com/problems/n-queens/submissions/

TC - O(N!)
SC - O(N^2)
Aux SC - O(N)

Instead of O(n) iteration we can optimize the last approach to O(1) using map. 

Queen Can attack -
1. Row wise.
2. Column Wise.
3. Diagonally.

What will be key in the map??

For Row Check -Here key will be row number. We only need to check left rows of current column.We can use DAT(Direct Address Table) for that as the size of the map is fixed = number of rows.
Just check if any queen already present on a particular row in O(1) time complexity from the LeftRow Vector.If the ith index of LeftRow is true it means that ith row already has an queen so it is not safe to place another queen in the same row.

For Lower Diagonal- Key will be row+col.
Let n= 4

    0 1 2 3 
0   0 1 2 3
1   1 2 3 4
2   2 3 4 5
3   3 4 5 6

Take an array of size 2n-1,in case of 4 it is 7. If the queen is going to attacked by the existing queen in the lower diagonal the lowerDiagonal[row+col] will be true.

For upper Diagonal- fill the board on the basis of n-1+(col-row) which is key.
Let n= 4

    0 1 2 3 
0   3 4 5 6
1   2 3 4 5
2   1 2 3 4
3   0 1 2 3


Take an array of size 2n-1. If the queen is going to attacked by the existing queen in the upper diagonal the upperDiagonal[n-1+(col-row)] will be true.
*/

class Solution 
{
public:   
    void check(int n,vector<string>&board,vector<vector<string>> &result,int  col,vector<bool>&LeftRow,vector<bool>& upperDiagonal,vector<bool> &lowerDiagonal)
    {
        if(col==n)
        {
            result.push_back(board);
            return;
        }
        
        for(int row=0;row<n;row++)
        {
            if(!LeftRow[row] and  !upperDiagonal[n-1+(col-row)] and !lowerDiagonal[row+col])
            {
                board[row][col]='Q';
                LeftRow[row]=true;
                lowerDiagonal[row+col]=true;
                upperDiagonal[n-1+(col-row)]=true;
                
                check(n,board,result,col+1,LeftRow,upperDiagonal,lowerDiagonal);
                
                board[row][col]='.';
                LeftRow[row]=false;
                lowerDiagonal[row+col]=false;
                upperDiagonal[n-1+(col-row)]=false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) 
    {
        vector<vector<string>> result;
        
        string s(n,'.');
        vector<string> board(n,s);
        
        vector<bool> LeftRow(n,false);
        vector<bool> upperDiagonal(2*n-1,false);
        vector<bool> lowerDiagonal(2*n-1,false);
        
        int col=0;
        
        check(n,board,result,col,LeftRow,upperDiagonal,lowerDiagonal);
        
        return result;
    }
};


