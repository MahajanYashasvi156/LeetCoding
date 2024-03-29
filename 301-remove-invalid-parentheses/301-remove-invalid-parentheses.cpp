class Solution 
{
    void solve(string &s, int index ,string path,set<string>&result,int &maxi,int count)
    {
        if(count<0)
            return ;
        if(index==s.size())
        {
            if(count ==0 and (maxi==-1 || maxi==path.size()))
            {
                result.insert(path);
                maxi = path.size();
            }
            return;
        }
        
        if(s[index]=='(')
        {
             //picking
            solve(s,index+1,path+s[index],result,maxi,count+1);
            solve(s,index+1,path,result,maxi,count);
        }
        else if(s[index]==')')
        {
             //picking
            solve(s,index+1,path+s[index],result,maxi,count-1);
            solve(s,index+1,path,result,maxi,count);
        }
        else 
        {
            solve(s,index+1,path+s[index],result,maxi,count);  
        }
        
    }
public:
    vector<string> removeInvalidParentheses(string s) 
    {
        set<string> result;
        string path = "";
        int count = 0;
        int maxi = -1;
        solve(s,0,path,result,maxi,count);
        return {result.begin(),result.end()};
    }
};