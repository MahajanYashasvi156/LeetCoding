class Solution 
{
public:
    string shortestPalindrome(string s) 
    {
        string text = s;
        string temp = s;
        reverse(temp.begin(),temp.end());
        text = text + "$" + temp;
        int i = 1;
        int j = 0;
        vector<int> lps(text.size(),0);
        while(i<text.size())
        {
            while(j>0 and text[i]!=text[j])
            {
                j = lps[j-1];
            }
            if(text[i]==text[j])
            {
                lps[i] = j+1;
                j++;
                i++;
            }
            else
            {
                lps[i] = j;
                i++;
            }
        }
        int addingChar = s.size() - lps[text.size()-1];
        string addedString = s.substr(s.size()-addingChar,addingChar);
        reverse(addedString.begin(),addedString.end());
        return  addedString+ s;
    }
};