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