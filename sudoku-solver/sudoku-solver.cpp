/*
Link - https://leetcode.com/problems/sudoku-solver/submissions/
Approach - We have to fill entire board, so go recursively on each cell in row major form while trying all 9 options in the cell.
Before trying any option in empty cell check if trying that option will make sudoku invalid
If sudoku is valid, try that option and go to next cell
If sudoku is invalid, then try different option

If cell is already filled, then just move to next cell
TC - O(9^(n^2))
ASC- O(n^2)
SC - O(1)
*/
class Solution 
{
public:
     bool isValidSudoku(vector<vector<char>>& board,int row,int col,char c)
    {
         //Check for row
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == c)
                return false;
        }
         
         //Check for column
         for(int i=0;i<9;i++)
         {
            if(board[row][i] == c)
                return false;
         }
         
        //Check for block - row/3 and col/3 to go to the beginning of the block.
        row=row/3;
        col=col/3;
         
        for(int i=3*row;i<3*row+3;i++)
        {
            for(int j=3*col;j<3*col+3;j++)
            {
                if(board[i][j]==c)
                     return false;
            }
        }
        return true;
    }
    
    /*
    bool isValidSudoku(vector<vector<char>>& board,int row,int col,char c)
    {
        for(int i=0;i<9;i++)
        {
            //Check for row
            if(board[i][col] == c)
                return false;
            
            //Check for column
            if(board[row][i] == c)
                return false;
            
            //Check for block - row/3 and col/3 to go to the beginning of the block.
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c)
                return false;
        }
        return true;
    }
    */
    bool solveSudokuUtility(vector<vector<char>>& board,int c)
    {
        int row=c/9;
        int col=c%9;
        if(c==81)
            return true;
        
        if(board[row][col]=='.')
        {
           for(char i = '1';i<='9';i++)
           {
               if(isValidSudoku(board,row,col,i))
               {

                  board[row][col]= i;
                  if(solveSudokuUtility(board,c+1))
                    return true;
                  board[row][col]= '.';
               } 
           }
        }
        else if(solveSudokuUtility(board,c+1))
                return true;
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solveSudokuUtility(board,0);
    }
};