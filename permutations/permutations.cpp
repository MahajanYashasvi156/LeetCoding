class Solution 
{
public:
    void generatePermutations(vector<int>& nums,vector<int>& path,vector<vector<int>>&res,vector<int>&taken)
    {
        if(path.size()==nums.size())
        {
            res.push_back(path);
            return;
        }   
        for(int i=0;i<nums.size();i++)
        {   
            if(taken[i]==0)
            {
                 path.push_back(nums[i]);
                 taken[i]=1;
                 generatePermutations(nums,path,res,taken);
                 taken[i]=0;
                 path.pop_back();
            }
            
        }
    }
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>>res;
        vector<int> path;
        vector<int> taken(nums.size(),0);
        generatePermutations(nums,path,res,taken);
        return res;
    }
};