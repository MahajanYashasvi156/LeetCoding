class Solution 
{
public:
    
    void genrateCombinations(vector<string>&phone,string &digits,int index,vector<string>&res,string &comb)
    {
        cout<<index;
        if(index==digits.size())
        {
            res.push_back(comb);
            return;
        }
        for(int i=0;i<phone[digits[index]-'0'].size();i++)
        {
            comb.push_back(phone[digits[index]-'0'][i]);
            genrateCombinations(phone,digits,index+1,res,comb);
            comb.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> phone(10);
        vector<string> res;
        if(digits.size()==0)
            return res;
        phone[2]="abc";
        phone[3]="def";
        phone[4]="ghi";
        phone[5]="jkl";
        phone[6]="mno";
        phone[7]="pqrs";
        phone[8]="tuv";
        phone[9]="wxyz";
        int index=0;
        string comb;
        genrateCombinations(phone,digits,index,res,comb);
        return res;
    }
};