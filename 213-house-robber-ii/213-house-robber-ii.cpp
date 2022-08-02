class Solution
{
public:
    int rob(vector<int>& nums) 
    {
        if(nums.size()==1)
            return nums[0];
        int notpickFirst = 0;
        int notpickLast = 0;
        
        int prev2 ;
        int prev = nums[1];
        for(int i = 2;i<nums.size();i++)
        {
            int pick = nums[i];
            if(i>2)
                pick = pick + prev2;
            int notPick = prev;
            prev2 = prev;
            prev = max(pick,notPick);
        }
        notpickFirst = prev;
        
        prev = nums[0];
        for(int i = 1;i<nums.size()-1;i++)
        {
            int pick = nums[i];
            if(i>1)
                pick = pick + prev2;
            int notPick = prev;
            prev2 = prev;
            prev = max(pick,notPick);
        }
        notpickLast = prev;
        
        return max(notpickFirst,notpickLast);
        
    }
};