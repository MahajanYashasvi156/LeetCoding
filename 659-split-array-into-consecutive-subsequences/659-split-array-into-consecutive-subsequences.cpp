/*
    Algorithm - 
    
    1. Make a map - key value - element,index
    
    2. Make a count Array to store the max possible length till current.
    
    3. Check nums[i] -1 exist in map if yes then pick the one with the minimum count value. Set its count value = -1 and remove that previous elemnt from the map also.
    
    4. Check if all elements should have count values either -1 or >=3

*/
class Solution 
{
public:
    bool isPossible(vector<int>& nums)
    {
        unordered_map<int,vector<int>> index;
        
        vector<int> count(nums.size(),INT_MAX);
        
        for(int i = 0;i<nums.size();i++)
        {
            if(index.find(nums[i]-1)!=index.end())
            {
                int mini = INT_MAX;
                int previndex = -1;
                int c = 0;
                int m = -1;
                for(int j:index[nums[i]-1])
                {
                    if(mini>count[j])
                    {
                        mini = count[j];
                        previndex = j;
                        m = c;
                    }
                    c++;
                }
               
                index[nums[i]-1].erase(index[nums[i]-1].begin()+m);
                if(index[nums[i]-1].size()==0)
                    index.erase(nums[i]-1);
                
                count[i] = count[previndex]+1;
                count[previndex] = -1;
            }
            else
                count[i] = 1;
        
            index[nums[i]].push_back(i);
        }
        for(int c : count)
        {
            if(c<3 and c!=-1)
                return false;
        }
        return true;
    }
};