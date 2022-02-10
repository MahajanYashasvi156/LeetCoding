class Solution {
public:
    int subarraySum(vector<int>& nums, int k) 
    {
        vector<int> prefixSum(nums.size());
        map<int,int> freq;//(prefixSum,freq)
        
        int count=0;
        
        freq[0]=1;
        
        for(int i=0;i<nums.size();i++)
        {
            if(i==0)
                prefixSum[i]=nums[i];
            else
                 prefixSum[i]=prefixSum[i-1]+nums[i];
            
            if(freq.find(prefixSum[i]-k)!=freq.end())
                count+=freq[prefixSum[i]-k];
            
            freq[prefixSum[i]]++;
            
            
        }
        return count;
        
    }
};