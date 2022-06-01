class Solution 
{
public:
    bool validPalindrome(string A)
    {
    
       int low = 0;
       int high = A.size()-1;

       while(low<high)
       {
           if(A[low]==A[high])
           {
               low++;
               high --;
           }
           else
                break;
       } 
       if(low>=high)
            return 1;

        int low1 = low+1;
        int high1 = high;
        while(low1<high1)
        {
           if(A[low1]==A[high1])
           {
               low1++;
               high1 --;
           } 
           else
                break;
        }
        if(low1>=high1)
            return 1;

        int low2 = low;
        int high2 = high-1;
        while(low2<high2)
        {
           if(A[low2]==A[high2])
           {
               low2++;
               high2 --;
           } 
           else
                return 0;;
        }
        return 1;
    }
};