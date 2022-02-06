class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int c = 0;
        int k = nums.size();
        int v = INT_MAX;
        
        for(int i=0;i<nums.size();i++)
        {
            if(c==2 and nums[i]==v)
            {
                k--;
                nums[i]=INT_MAX;
            }
            else if(nums[i]==v)
                c++;
            else
            {
               v=nums[i];
                c=1;
            }  
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};