class Solution 
{
public:
    bool isValidSudoku(vector<vector<char>>& A) 
    {
        for(int r = 0;r<9;r++)
        {
            vector<int> row(10,0);
            for(int c = 0;c<9;c++)
            {
                if(A[r][c]=='.')
                    continue;
                if(row[A[r][c]-'0']==1)
                     return 0;
                row[A[r][c]-'0'] = 1;
            }
        }
    
        for(int c = 0;c<9;c++)
        {
            vector<int> col(10);
            for(int r = 0;r<9;r++)
            {
                if(A[r][c]=='.')
                    continue;
                if(col[A[r][c]-'0']==1)
                    return 0;
                col[A[r][c]-'0'] = 1;
            }
        }

        for(int i = 0;i<3;i++)
        {
            for(int j = 0;j<3;j++)
            {
                vector<int> block(10);
                for(int r= 3*i;r<3*i+3;r++)
                {
                    for(int c=3*j;c<3*j+3;c++)
                    {
                        if(A[r][c]=='.')
                            continue;
                        if(block[A[r][c]-'0']==1)
                            return 0;
                        block[A[r][c]-'0'] = 1;
                    }
                }
            }
        }
        return 1;
    }
};

//https://leetcode.com/problems/valid-sudoku/submissions/
//Time = O(1)
//Space = O(1) 

/*
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
};
*/