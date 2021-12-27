class Solution 
{
public:
    void subsetsWithDupUtility(vector<int> nums,int index,set<vector<int>>&setResult,vector<int>path)
    {
       
        if(index==nums.size())
        {
            sort(path.begin(),path.end());
            setResult.insert(path);
            return;
        }
        path.push_back(nums[index]);
        subsetsWithDupUtility(nums,index+1,setResult,path) ;
        path.pop_back();
        subsetsWithDupUtility(nums,index+1,setResult,path) ;
    }
        
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        set<vector<int>> setResult;
        vector<vector<int>> result;
        vector<int> path;
        subsetsWithDupUtility(nums,0,setResult,path) ;
        for(auto a: setResult)
            result.push_back(a);
        return result;
    }
};