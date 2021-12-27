class Solution 
{
public:
    void combinationSumUtility(vector<int>& candidates,int index,int target,set<vector<int>>&setResult,vector<int> comb)
    {
        if(target<0)
            return;
        if(target==0)
        {
            sort(comb.begin(),comb.end());
            setResult.insert(comb);
        }
            
        if(index==candidates.size())
            return;
        comb.push_back(candidates[index]);
        combinationSumUtility(candidates,index+1,target-candidates[index],setResult,comb);
        combinationSumUtility(candidates,index,target-candidates[index],setResult,comb);
        comb.pop_back();
        combinationSumUtility(candidates,index+1,target,setResult,comb);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        set<vector<int>>setResult;
        vector<vector<int>>result;
        vector<int>comb;
        combinationSumUtility(candidates,0,target,setResult,comb);
        for(auto a: setResult)
            result.push_back(a);
        return result;
    }
};