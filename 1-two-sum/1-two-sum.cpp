class Solution 
{
public:
    vector<int> twoSum(vector<int>& A, int target) 
    {
        unordered_map<int,int> m;
 
        for(int i = 0;i<A.size();i++)
        {
            if(m.find(target-A[i])!=m.end())
                return {m[target-A[i]],i};

            if(m.find(A[i])==m.end())
                m[A[i]]=i;
        }
        return {};
    }
};

/*
class Solution 
{
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        int left=0;
        int right=nums.size()-1;
        sort(nums.begin(),nums.end());
        while(left<right)
        {
             if(nums[left]+nums[right]==target)
                   return {left,right};    
             if(nums[left]+nums[right]<target)
                  left++;
              else
                  right--;       
        }
        return {};
    }
};
*/