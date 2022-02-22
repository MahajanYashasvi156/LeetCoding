/*
Link - https://leetcode.com/problems/excel-sheet-column-number/submissions/

*/
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int ans=0;
        for(char col:columnTitle)
        {
            ans = ans*26;
            ans+=(col-'A'+1);
        }
        return ans;
    }
};