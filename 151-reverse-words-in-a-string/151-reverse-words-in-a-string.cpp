class Solution 
{
public:
    string reverseWords(string s) 
    {
        reverse(s.begin(),s.end());
        int start = 0;
        while(s[start]==' ')
        {
            s.erase(s.begin());
        }

        int end = 0;
        while(end<s.size())
        {
            if(s[end]==' ')
            {
                reverse(s.begin()+start,s.begin()+end);
                end++;
                while(s[end]==' ')
                   s.erase(s.begin()+end);
                start = end;
            }
            else
                end++;
        }
        if(s[end-1]==' ')
            return {s.begin(),s.end()-1};
        reverse(s.begin()+start,s.begin()+end);
        return s;
    }
};

/*
class Solution 
{
    public:
    string reverseWords(string s)
    {
        string result = "";
        for(int i = s.size()-1;i>=0;i--)
        {
            int lenOfWord = 0;
            while(i>=0 and s[i]!=' ')
            {
                lenOfWord++;
                i--;
            }
            if(lenOfWord>0)
            {
                result = result + s.substr(i+1,lenOfWord)+" ";
            }
        }
        return result.substr(0,result.size()-1);
    }
};
*/