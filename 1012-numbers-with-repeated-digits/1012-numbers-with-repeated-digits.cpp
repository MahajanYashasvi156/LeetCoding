class Solution
{
    int noRepeatation(string &s, int index, bool tight, int mask,vector<vector<vector<int>>>&dp)
    {
        //Only no 0 can't be the valid no so if there is any other no formed till now so it would be counted as no with no repeation except 0.
        if(index==s.size())
            return mask!=0;
        
        if(dp[index][tight][mask]!=-1)
            return dp[index][tight][mask];
        
        int ub = tight?(s[index]-'0'):9;
        
        int ans = 0;
       
        for(int digit = 0;digit<=ub;digit++)
        {
            //if mask == 0 means till now we have not started forming our number. Also if curr digit = 0 means still we can't start forming our number. current 0 will also be leading 0 only.
            if(mask==0 and digit==0)
                ans +=noRepeatation(s,index+1,tight and (digit==ub),mask,dp);
            
            //If the current digit is already taken in the formation of number then no need to go onwards as it will be never be a no with no repeatation
            else if(mask & (1<<digit))
                continue;
            
            //If the no is neither leading 0 nor digit is repeated we can move onwards by updating mask to count no of non repeating no with curr prefix.
            else
                 ans+=noRepeatation(s,index+1,tight and (digit==ub),mask | (1<<digit),dp);
           
        }
        return dp[index][tight][mask] = ans;
    }
public:
    int numDupDigitsAtMostN(int n) 
    {
        string s = to_string(n);
        
        //We need 10 bits to know which digits already appeared in the no. So we use 10 LSB bits of integer to get this information. With 10 no.'s  0-9 we may have 1024 diffrent mask(1>>10) so we declared 3D Dp of size index * tight * mask.
        
        vector<vector<vector<int>>> dp(s.size(),vector<vector<int>>(2,vector<int>(1024,-1)));
        
        //Total No - No with no repeatation.
        return n - noRepeatation(s,0,true,0,dp);
    }
};