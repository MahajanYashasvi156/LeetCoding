class Solution 
{
public:
    int lengthOfLastWord(string A) 
    {
        int result = 0;
        for(int i = A.size()-1;i>=0;i--)
        {
            if(A[i]==' ' and result!=0)
            {
                break;
            }
            else if(A[i]!=' ')
                result++;
        }
        return result;
    }
};