class Solution {
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
            {
                result = max(result,i-prefixSumIndex[s]);
            }
            else
                prefixSumIndex[s]=i;
                
        }
        return result;
    }
};