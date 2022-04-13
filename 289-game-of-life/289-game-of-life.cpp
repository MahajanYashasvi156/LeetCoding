/*
0 or 1 live -> die
2 or 3 live ->live
4 or more ->dies
dead 3 live ->live
*/
class Solution 
{
    int countLive(vector<vector<int>>&temp,int i,int j)
    {
        int live =0;
        if(i>0 and temp[i-1][j])
            live++;
        if(j>0 and temp[i][j-1])
            live++;
        if(i<temp.size()-1 and temp[i+1][j])
            live++;
        if(j<temp[0].size()-1 and temp[i][j+1])
            live++;
        
        if(i>0 and j>0 and temp[i-1][j-1])
            live++;
        if(i>0 and j<temp[0].size()-1 and temp[i-1][j+1])
            live++;
        if(i<temp.size()-1 and j>0 and temp[i+1][j-1])
            live++;
        if(i<temp.size()-1 and j<temp[0].size()-1 and temp[i+1][j+1])
            live++;
        return live;
    }
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        vector<vector<int>> temp = board;
        int live;
        for(int i=0;i<temp.size();i++)
        {
            for(int j =0;j<temp[0].size();j++)
            {
                live = countLive(temp,i,j);
                if(temp[i][j]==1)
                {
                    if(live <2 or live >=4)
                    {
                        board[i][j]=0;
                    }
                }
                else
                {
                    if(live ==3)
                    {
                         board[i][j]=1;
                    }
                        
                }
            }
        }
    }
};