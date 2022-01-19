/*
Link - https://leetcode.com/problems/decode-ways/
TC - O(N)
SC - O(N)
*/

class Solution
{
public:
    int numDecodings(string s) 
    {
        vector<int>numOfEncodings(s.size(),0);
        if(s[0]=='0')
            return 0;
        numOfEncodings[0]=1;
        
        for(int i=1;i<s.size();i++)
        {
            //Two consecutive zero not possible
            if(s[i-1]=='0' and s[i]=='0' ) 
            {
                numOfEncodings[i]=0;
            }
            else if(s[i-1]=='0' and s[i]!='0') 
            {
                numOfEncodings[i]=numOfEncodings[i-1];
            }
            else if (s[i-1]!='0' and s[i]=='0')
            {
                if(s[i-1]=='1' or s[i-1]=='2')
                {
                    if(i>=2)
                        numOfEncodings[i]= numOfEncodings[i-2];
                    else
                        numOfEncodings[i]=1;
                }    
                else
                    numOfEncodings[i]=0;
            }
            else
            {
                int first=s[i-1]-'0';
                int second = s[i]-'0';
                int num=first*10+second;
                
                if(num>0 and num<=26)
                {
                    if(i>=2)
                        numOfEncodings[i]= numOfEncodings[i-2];
                    else
                        numOfEncodings[i]= 1;
                }
                numOfEncodings[i]+= numOfEncodings[i-1];
            }
            
        }
        return numOfEncodings[s.size()-1];
    }
};