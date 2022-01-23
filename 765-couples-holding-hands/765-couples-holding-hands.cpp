/*
Link - https://leetcode.com/problems/couples-holding-hands/submissions/
TC - O(N^2)
SC - O(1)

Approach 1 - Greedy

*/
class Solution 
{
public:
    int minSwapsCouples(vector<int>& row) 
    {
        int count =0;
        int n = row.size();
        for(int i=0;i<n;i=i+2)
        {
            int toFind ;
            int index;
            if(row[i]%2==0)
                toFind=row[i]+1;
            else
                toFind = row[i]-1;
            
            for(int j=i+1;j<n;j++)
            {
                if(row[j]==toFind)
                {
                    index=j;
                    break;
                }  
            }
            if(index!=i+1)
            {
                swap(row[i+1],row[index]);
                 count++;
            }
               
        }
        return count;
    }
};