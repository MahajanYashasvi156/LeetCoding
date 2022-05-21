
/*
class Solution 
{
public:
    void setZeroes(vector<vector<int>>& A) 
    {
        set<int> Row ;
        set<int> Col;

        for(int i =0;i<A.size();i++)
        {
            for(int j =0;j<A[i].size();j++)
            {
                if(A[i][j] == 0)
                {
                    Row.insert(i);
                    Col.insert(j);
                }
            }
        }

        for(int i =0;i<A.size();i++)
        {
            for(int j =0;j<A[i].size();j++)
            {
                if(Row.find(i)!=Row.end() or Col.find(j)!=Col.end())
                {
                    A[i][j] = 0;
                }
            }
        }
    }
};
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& A) 
    {
        int row = A.size();
        int col = A[0].size();

        bool hasRowZero = false;
        bool hasColZero = false;

         // Does first column have zero?
        for(int i=0;i<row;i++)
        {
            if(A[i][0]==0)
            {
                hasColZero = true;
                break;
            }      
        }
         // Does first row have zero?
        for(int j=0;j<col;j++)
        {
            if(A[0][j]==0)
            {
                hasRowZero = true;
                break;
            }      
        }
         // find zeroes and store the info in first row and column
        for(int i =1;i<row;i++)
        {
            for(int j =1;j<col;j++)
            {
                if(A[i][j] == 0)
                {
                    A[0][j] = 0;
                    A[i][0] = 0;
                }
            }
        }
         // set zeroes except the first row and column
        for(int i =1;i<row;i++)
        {
            for(int j =1;j<col;j++)
            {
                if(A[0][j] == 0 or A[i][0] == 0)
                {
                    A[i][j] = 0;
                }
            }
        }
         // set zeroes for first row and column if needed
        if(hasRowZero)
        {
            for(int j=0;j<col;j++)
            {
                A[0][j]=0; 
            }
        }
        if(hasColZero)
        {
            for(int i=0;i<row;i++)
            {
                A[i][0]=0;
            }
        }

    }
};