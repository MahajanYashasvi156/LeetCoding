class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int checker[10];
        
        //Check Validity of Row
        for(int i=0;i<9;i++)
        {
            memset(checker,0,sizeof(checker));
            for(int j=0;j<9;j++)
            {
                if(board[i][j]!='.' and checker[board[i][j]-48]!=0)
                    return false;
                else if(board[i][j]!='.')
                    checker[board[i][j]-48]=1;
            } 
        }
        
        //Check Validity of Column
        for(int i=0;i<9;i++)
        {
            memset(checker,0,sizeof(checker));
            for(int j=0;j<9;j++)
            {
                if(board[j][i]!='.' and checker[board[j][i]-48]!=0)
                    return false;
                else if(board[j][i]!='.')
                    checker[board[j][i]-48]=1;
            } 
        }

        //Check Validity of Block
        for(int row=0;row<3;row++)
        {
            for(int col=0;col<3;col++)
            {
             memset(checker,0,sizeof(checker));
                for(int i=row*3;i<row*3+3;i++)
                {
                    for(int j=col*3;j<col*3+3;j++)
                    {
                        if(board[i][j]!='.' and checker[board[i][j]-48]!=0)
                            return false;
                        else if(board[i][j]!='.')
                            checker[board[i][j]-48]=1;
                    } 
                }
            }
        }
    
        return true;
    }
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
               board[row][col]= i;
               if(isValidSudoku(board))
               {
                   if(solveSudokuUtility(board,c+1))
                        return true;
                 
               }
               board[row][col]= '.';
           }
        }
        else
        {
            if(solveSudokuUtility(board,c+1))
                   return true;
                        
        }
        return false;
        
    }
    
    void solveSudoku(vector<vector<char>>& board) 
    {
        solveSudokuUtility(board,0);
    }
};