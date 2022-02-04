/*
Link - https://leetcode.com/problems/contiguous-array/

TC - O(N)
SC - O(N)
*/
class Solution 
{
public:
    int findMaxLength(vector<int>& nums) 
    {
        map<int,int> prefixSumIndex;
        int s = 0;
        int result =0;
        prefixSumIndex[0]=-1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
                s = s-1;
            else
                s = s + 1;
            
            if(prefixSumIndex.find(s)!=prefixSumIndex.end())
                result = max(result,i-prefixSumIndex[s]);

            else
                prefixSumIndex[s]=i;
                
        }
        return result;
    }
};

//Can also be done by susbstituting 0 with -1 . Find the lasrgest subarray with sum 0.
/*
class Solution {
public:
    int findMaxLength(vector<int>& nums)
    {
        unordered_map<int,int> freq;//count,index;
        freq[0]=-1;
        int count=0;
        int maxlen=0;
        for(int i=0;i<nums.size();i++)
       {
           if(nums[i]==0)
               count++;
            else
                count--;
            if(freq.find(count)!=freq.end())
                maxlen=max(maxlen,i-freq[count]);
            else
                freq[count]=i;
       }
        return maxlen;
    }
};
*/