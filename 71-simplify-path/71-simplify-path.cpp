class Solution 
{
    
    
public:
    string simplifyPath(string path) 
    {
        stack<string> s;
        
        for(int i = 0; i<path.size();i++)
        {
            if(path[i]=='/')
                continue;
            string temp ;
            while(i<path.size() and path[i]!='/')
            {
                temp = temp + path[i];
                i++;
            }
            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!s.empty())
                    s.pop();
            }
            else 
                s.push(temp);
        }
        string result;
        while(!s.empty())
        { 
            result ="/"+ s.top() + result;
            s.pop();  
        }
        if(result.size()==0)
            result="/";
        return result;
    }
};

