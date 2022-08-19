class Solution 
{
    void solve(string &s, int index ,string path,set<string>&result,int left,int right,int count)
    {
        if(left<0 or right<0 or count<0)
            return ;
        if(index==s.size())
        {
            if(left==0 and right==0)
                result.insert(path);
            return;
        }
        if(s[index]!='(' and s[index]!=')')
        {
            solve(s,index+1,path+s[index],result,left,right,count);
        }
        else
        {
            //Discarding
            if(s[index]=='(')
            {
                solve(s,index+1,path,result,left-1,right,count);
            }
            else if(s[index]==')')
            {
                solve(s,index+1,path,result,left,right-1,count);
            }
            //picking
            solve(s,index+1,path+s[index],result,left,right,s[index]=='('?count+1:count-1);
        }
        
    }
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        int left = 0;
        int right = 0;
        
        for(char c:s)
        {
            if(c=='(')
            {
                left++;
            }
            else if(c==')')
            {
                if(left)
                    left--;
                else
                    right++;
            }
        }
        set<string> result;
        string path = "";
        int count = 0;
        
        solve(s,0,path,result,left,right,count);
        return {result.begin(),result.end()};
    }
};