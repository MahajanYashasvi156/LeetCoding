class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
         //Sorting to use two ptr approach
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        for(int i = 0;i<nums.size();i++)
        {
            //If we got positive ele, then further eles are also positive(sorted array), 
            //hence sum can't be 0 so we can break loop 
            if(nums[i]>0) break;
             //If we got same ele again, then we can skip it 
            //As the combinations possible are already processed by previous ele
            if(i>0 and nums[i]==nums[i-1])
                continue;
            
            
            int low = i+1;
            int high = nums.size()-1;
            while(low<high)
            {
                int sum = nums[i]+nums[low]+nums[high];
                
                //examining sum
                //if desired then note the triplet
                if(sum==0)
                {
                    result.push_back({nums[i],nums[low],nums[high]});
                    low++;
                    high--;
                    while(low<high and nums[low-1]==nums[low]) low++;
                }
                //if greater than desired 
                //then need smaller sum, so decrement high(taking smaller ele)
                else if(sum>0)
                {
                    high--;
                }
                    //if less than desired 
                //then need greater sum, so increament low(taking bigger ele)
                else
                {
                    low++;
                }
            }
        }
        
        return result;
    }
};