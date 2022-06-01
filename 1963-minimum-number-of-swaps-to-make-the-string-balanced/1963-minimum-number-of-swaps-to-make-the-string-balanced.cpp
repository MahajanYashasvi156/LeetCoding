class Solution 
{
    public:
    int minSwaps(string s) 
    {
        int incorrect = 0;
        int open = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i]==']' and open==0)
                incorrect++;
            else if(s[i]=='[') open++;
            else 
            {
                open--   ;
            }  
                
        }
        return (incorrect+1)>>1;
        /*
        int low = 0;
        int high = s.size()-1;
        int countleft = 0;
        int countright = 0;
        int result = 0;
        while(low<high)
        {
            while(low<high and (s[low]=='[' or countleft>0))
            {
                if(s[low] == '[')
                {
                    countleft = countleft + 1;
                }
                else
                    countleft = countleft -1;
                low++;
            }
            while(low<high and (s[high]==']' or countright>0))
            {
                if(s[high] == ']')
                {
                    countright = countright + 1;
                }
                else
                    countright = countright -1;
                high--;
            }
            if(low<high)
            {
                result = result +1;
                countleft = 1;
                countright = 1;
                low++;
                high--;
            }
        }
        return result;
        */
    }
};