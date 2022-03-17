class Solution 
{
    int scoreUtility(string s,int sindex,int eindex)
    {
        if(sindex >= eindex)
            return 0;
        int count=0;
        for(int i = sindex;i< eindex;i++)
        {
            if(s[i]=='(')
                count++;
            else 
                count --;
            if(count ==0)
            {
                if(sindex == i-1)
                    return 1+scoreUtility(s,i+1,eindex);
                return 2*scoreUtility(s,sindex+1,i)+scoreUtility(s,i+1,eindex);
            }  
        }
        return 0;
    }
public:
    int scoreOfParentheses(string s) 
    {
       return  scoreUtility(s,0,s.size());
    }
};