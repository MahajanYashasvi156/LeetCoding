class Solution {
public:
void subsetSumUtility(vector<int> arr,vector<vector<int>>&res,int index,vector<int>&path)
{
    if(index==arr.size())
    {
        res.push_back(path);
        return;
    }
    //Pick the element at index.
    path.push_back(arr[index]);
    subsetSumUtility(arr,res,index+1,path);
    path.pop_back();
    //Don't pick the element at index.
    subsetSumUtility(arr,res,index+1,path);
}
    
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<vector<int>>res;
        vector<int>path;
        subsetSumUtility(nums,res,0,path);
        return res;
    }
};