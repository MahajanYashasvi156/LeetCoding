class Solution 
{
    bool ispossible(vector<int>& nums, int k,int diff)
    {
        int pairswithdiffsmallerthanDiff = 0;
        int j = 0;
        for(int i = 0;i<nums.size();i++)
        {
            while(j<nums.size() and abs(nums[j]-nums[i])<=diff)
            {
                j++;
            }
            pairswithdiffsmallerthanDiff+=(j-i-1);
        }
        return pairswithdiffsmallerthanDiff>=k;
        
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        int low = 0;
        int high = 1000000;
        
        int candidateAns = -1;
        sort(nums.begin(),nums.end());
        while(low<=high)
        {
            int diff = (low+high)/2;
            
            if(ispossible(nums,k,diff))
            {
                candidateAns = diff;
                high = diff-1;
            }
            else
            {
                low = diff+1;
            }
        }
        return candidateAns;
        
    }
};

/*
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) 
    {
        priority_queue<int> maxheap;
        
        for(int i = 0;i<nums.size();i++)
        {
            for(int j = i+1;j<nums.size();j++)
            {
                int diff = abs(nums[i]-nums[j]);
                if(maxheap.size()<k)
                {
                    maxheap.push(diff);
                }
                else 
                {
                    if(maxheap.top()>diff)
                    {
                        maxheap.pop();
                        maxheap.push(diff);
                    }
                }
            }
        }
        return maxheap.top();
    }
};

*/