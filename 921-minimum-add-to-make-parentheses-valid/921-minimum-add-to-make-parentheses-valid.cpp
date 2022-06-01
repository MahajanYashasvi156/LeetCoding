class Solution 
{
public:
    int minAddToMakeValid(string s) 
    {
        int count = 0;
        int result = 0;
        for(int i =0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                count++;
            }
            else 
            {
                if(count>0)
                {
                    count--;
                }
                else
                {
                    result++;
                }
            }
        }
        return result+count;
        
    }
};