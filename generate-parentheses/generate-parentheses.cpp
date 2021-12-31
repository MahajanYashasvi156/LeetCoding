class Solution 
{
public:
    void generateParenthesisUtility(int n,vector<string>&result,int open,int close,string path)
    {
        if(open>n or close>n or close>open)
            return;
        if(open==n and close==n)
        {
            result.push_back(path);
            return;
        }
        generateParenthesisUtility(n,result,open+1,close,path+"(");
        generateParenthesisUtility(n,result,open,close+1,path+")");
    }
    vector<string> generateParenthesis(int n) 
    {
        vector<string> result;
        int open=0;
        int close=0;
        string path;
        generateParenthesisUtility(n,result,open,close,path);
        return result;
    }
};