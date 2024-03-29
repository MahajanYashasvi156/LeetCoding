
/*
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
*/


class Solution 
{
public:
    string simplifyPath(string path) 
    {
        deque<string> dq;
        for(int i = 0; i<path.size();i++)
        {
            if(path[i]=='/')
                continue;
            string temp;
            while(i<path.size() and path[i]!='/')
            {
                temp +=path[i];
                i++;
            }
            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(!dq.empty())
                    dq.pop_back();
            }
            else 
                dq.push_back(temp);
        }

        string result = "";
        while(!dq.empty())
        { 
            result.append("/"+dq.front());
            dq.pop_front();  
        }
        if(result.size()==0)
            result="/";
        return result;
    }
};