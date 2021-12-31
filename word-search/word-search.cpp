/*
Link - https://leetcode.com/problems/word-search/

Appraoch - Slight modification of rat in maze problem.
At each cell intially check whether the first character match.
If the the first character of word matches then only explore it recursively in all four directions.

Since we can only take a character only once from the board so we have to maintain visited board so that we not take any cell charater more than one's.

If the current cell character matches with the word index character and it is not visited already then increment the word index and explore its 4 directions.
If the word index == word.size() that means we successfully searched the word in the board hence return true.

TC- O(m*n*(4^w)) 
m - no of rows in the board.
n- no of col in the board.
w- size of the word.

SC- O(m*n)
ASC- O(w)

class Solution 
{
public:
    bool wordSearch(vector<vector<char>>& board,vector<vector<bool>>& visited,int row,int col,string &word,int &wordIndex,int &m,int &n)
    {
        //Base case.
        if(wordIndex==word.size())
            return true;
        //Invalid case.
        if(row<0 or row>=m or col<0 or col>=n)
            return false;
        
        if(visited[row][col] or board[row][col]!=word[wordIndex])
            return false;
        
        visited[row][col]=1;
        
        wordIndex++;
        if(wordSearch(board,visited,row+1,col,word,wordIndex,m,n))
            return true;

        if(wordSearch(board,visited,row-1,col,word,wordIndex,m,n))
            return true;

        if(wordSearch(board,visited,row,col+1,word,wordIndex,m,n))
            return true;

        if(wordSearch(board,visited,row,col-1,word,wordIndex,m,n))
            return true;
        wordIndex--;
            
        visited[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        int wordIndex=0;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),0));
        
        int m=board.size();
        int n =board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(wordSearch(board,visited,i,j,word,wordIndex,m,n))
                        return true;
                }
                
            }
        }
        return false;
    }
};

*/

/*
Approach 2 - Slightly different approach

No need to maintain visited board
Just change the character of the word upon visiting it, so that it is corrupted and it will not be visited again as it is having some invalid data and not meaningful character.

a(97)-97=0 and A(65)-97=-32  both lie in some invalid albhabet character range.

We will change by subtracting ascii value of a

TC- O(m*n*(4^w)) 
m - no of rows in the board.
n- no of col in the board.
w- size of the word.

SC- O(1)
ASC- O(w)
*/
class Solution 
{
public:
    bool wordSearch(vector<vector<char>>& board,int row,int col,string &word,int wordIndex,int &m,int &n)
    {
        //Base case.
        if(wordIndex==word.size())
            return true;
        //Invalid case.
        if(row<0 or row>=m or col<0 or col>=n)
            return false;
        
        if(board[row][col]!=word[wordIndex])
            return false;
        
        board[row][col]-='a';
        
        if(wordSearch(board,row+1,col,word,wordIndex+1,m,n))
            return true;

        if(wordSearch(board,row-1,col,word,wordIndex+1,m,n))
            return true;

        if(wordSearch(board,row,col+1,word,wordIndex+1,m,n))
            return true;

        if(wordSearch(board,row,col-1,word,wordIndex+1,m,n))
            return true;
   
        board[row][col]+='a';
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        int wordIndex=0;
        int m=board.size();
        int n =board[0].size();
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
    
                    if(wordSearch(board,i,j,word,wordIndex,m,n))
                        return true;
            
                
            }
        }
        return false;
    }
};