class Solution 
{
    //using sliding window
public:
    bool rotateString(string s, string goal) 
    {
        if(goal.size()!=s.size())
            return false;
        
        s = s + s;
        int n = goal.size();
        
        int i = 1;
     
        while(i<s.size()-goal.size())
        {
            if(s.substr(i,n)==goal)
                return true;
            i++;
        }
        return false;
    }
};

//using KMP
/*
class Solution 
{
public:
    bool rotateString(string s, string goal) 
    {
        if(goal.size()!=s.size())
            return false;
        
        s = s + s;
        int n = goal.size();
        
        vector<int> lps(goal.size(),0);

        int i = 1;
        int j = 0;
    
        while(i<goal.size())
        {
            if(goal[i]==goal[j])
            {
                lps[i] = j+1;
                i++;
                j++;
            }
            else
            {
                if(j==0)
                    i++;
                else
                {
                    j = lps[j-1];
                }
            }
        }
    
        j = 0;
        i=0;
        while(i<s.size())
        {
            if(s[i]==goal[j])
            {
                i++;
                j++;
            }
            else
            {
                if(j>0)
                    j = lps[j-1];
                else
                    i++;
            }

            if(j==goal.size())
            {
                return true;
            }

        }
        if(j==goal.size())
            return true;
        return false;
    }
};
*/