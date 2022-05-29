/*
Link - https://leetcode.com/problems/excel-sheet-column-number/submissions/

TC - O(n) //Length of string
SC - O(1)

Topic - Number System.
*/
class Solution 
{
public:
    int titleToNumber(string columnTitle) 
    {
        long int place = 1;
        int i = columnTitle.size()-1;
        int ans = 0;
        while(i>=0)
        {
            ans = ans+ (columnTitle[i]-64)*place;
            place = place*26;
            i--;
        }
        return ans;
        /*
        int result = 0;
        int base = 1;
        for(int i=0;i<=columnTitle[i];i++)
        {
            result = result *26 + (columnTitle[i]-'A'+1);
        }
        return result;
        */
    }
};

