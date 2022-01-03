class Solution 
{
    public:
        int rangeBitwiseAnd(int left, int right) 
        {
            if(right==left )
                return right;
            int n;
            if(right==INT_MAX and left==0)
                n=INT_MAX;
            else
                n=right-left+1;
            int result=0;
            if(n==1)
                result+=1;
            for(int i=1;i<=log2(right);i++)//Loop for total no of bits.
            {
                   //If total numbers are greater than 2^i then there will surely be atleast one 0 in any number so resultant anding will be 0 for the ith bit so continue.
                    if(n>pow(2,i))
                        continue;
                
                    //Else check if for any element within the range of left to right ith bit is not set. 
                    bool flag=false;
                    for(long long int j=left;j<=right;j++)
                    {
                        //ith bit not set then it will go inside if condition.
                        if(!(j & (1<<i)))
                        {
                             flag=true;
                              break;
                        }
                        if(j==INT_MAX)
                            break; 
                    }
                    //If for all elements ith bit is set i.e. 1.
                    if(flag==false)
                        result=result+(1<<i);
            } 
            return result;
        }
};