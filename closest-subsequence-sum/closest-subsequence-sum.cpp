class Solution 
{
public:
    void generateSubSeqSum(vector<int>& nums,int index,int end,vector<int>& subSeqSum,int currSum)
    {
        if(index==end)
        {
            subSeqSum.push_back(currSum);
            return;
        }
        generateSubSeqSum(nums,index+1,end,subSeqSum,currSum);
        generateSubSeqSum(nums,index+1,end,subSeqSum,currSum+nums[index]);
    }
    
    
    int minAbsDifference(vector<int>& nums, int goal) 
    {
        vector<int> firstHalfSubSeqSum;
        vector<int> secondHalfSubSeqSum;
        int result=INT_MAX;
        int firstHalf=nums.size()/2;
        int start=0;
        int index=0;
        int currSum=0;
        generateSubSeqSum(nums,index,firstHalf,firstHalfSubSeqSum,currSum);
        generateSubSeqSum(nums,firstHalf,nums.size(),secondHalfSubSeqSum,currSum);
        
        sort(secondHalfSubSeqSum.begin(),secondHalfSubSeqSum.end());
       
        for(int i:firstHalfSubSeqSum)
        {
            int l=lower_bound(secondHalfSubSeqSum.begin(),secondHalfSubSeqSum.end(),goal-i)-secondHalfSubSeqSum.begin();
            int u=l-1;
            int temp=INT_MAX;
            if(l<secondHalfSubSeqSum.size() and l>=0)
                temp=abs(goal-i-secondHalfSubSeqSum[l]);
            if(u<secondHalfSubSeqSum.size() and u>=0)
                temp=min(temp,abs(goal-i-secondHalfSubSeqSum[u]));
            result=min(result,temp);
        }
        return result;
    }
};