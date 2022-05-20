
/*
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& B) 
    {
        int A = B.size();
        int totalSum = 0;
        for(auto a : B)
            totalSum += a;
        if(totalSum%3!=0)
            return 0;   
        int oneThird = totalSum/3 ;
        map<int,int> freq; 
        int currSum = 0;
        int ways = 0;
        for(int i=0;i<A-1;i++)
        {
            currSum = currSum+B[i];
            if(currSum == 2*oneThird and freq[oneThird]>0) // means we get the middle partition
            {
                return 1; //ways of getting first partition
            }
            freq[currSum]++;
        }
        //No of ways is getting first partition and middle partition only . Third partition depends on the selection of middle partition.
        return 0;
        
    }
};
*/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& B) 
    {
        int A = B.size();
        int totalSum = 0;
        for(auto a : B)
            totalSum += a;
        if(totalSum%3!=0)
            return 0;   
        int oneThird = totalSum/3 ;
        int currSum = 0;
        bool flag1 = false;
        bool flag2 = false;
        for(int i=0;i<A-1;i++)
        {
            currSum = currSum+B[i];
            if(currSum == oneThird && flag2 == false && flag1 == false)
            {
                flag1 = true;
            }
            else if(currSum == 2*oneThird && flag1 == true)
            {
                flag2 = true;
            }
            if(flag1 == true && flag2 == true)
                return 1;
        }
        return 0;
        
    }
};