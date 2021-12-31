class Solution 
{
public:
    bool wordSearch(vector<vector<char>>& board,vector<vector<bool>>& visited,int row,int col,string word,int wordIndex)
    {
        if(wordIndex==word.size())
            return true;
        
        if(row<0 or row>=board.size() or col<0 or col>=board[0].size())
            return false;
        
        if(visited[row][col]==1)
            return false;
        
        visited[row][col]=1;
        if(board[row][col]==word[wordIndex])
        {
            if(wordSearch(board,visited,row-1,col,word,wordIndex+1))
                return true;
            if(wordSearch(board,visited,row+1,col,word,wordIndex+1))
                return true;
            if(wordSearch(board,visited,row,col+1,word,wordIndex+1))
                return true;
            if(wordSearch(board,visited,row,col-1,word,wordIndex+1))
                return true;
        }
        visited[row][col]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word)
    {
        int wordIndex=0;
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),0));
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[i].size();j++)
            {
                if(wordSearch(board,visited,i,j,word,wordIndex))
                    return true;
            }
        }
        return false;
    }
};