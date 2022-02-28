class Solution 
{
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        vector<string> result;
        if(nums.size()==0)
            return result;
        int start = nums[0];
        int end = nums[0];
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==end+1)
                end = nums[i];
            
            else
            {
                string temp = to_string(start);
        
                if(start!=end)
                    temp = temp +"->"+to_string(end);
    
                result.push_back(temp);
                
                start=nums[i];
                end=nums[i]; 
            }
        }
        string temp = to_string(start);
        
        if(start!=end)
            temp = temp +"->"+to_string(end);
    
        result.push_back(temp);
        return result;
    }
};