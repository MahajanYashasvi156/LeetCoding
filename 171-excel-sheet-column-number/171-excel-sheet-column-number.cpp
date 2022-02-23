class Solution {
public:
    int titleToNumber(string columnTitle) 
    {
        int result = 0;
        int base = 1;
        for(int i=0;i<=columnTitle[i];i++)
        {
            result = result *26 + (columnTitle[i]-'A'+1);
        }
        return result;
    }
};