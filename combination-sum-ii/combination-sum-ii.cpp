class Solution {
public:
     void combinationSumUtility(vector<int>& candidates,int index,int target, vector<vector<int>>&result,vector<int>comb)
    {  
        if(target<0)
            return;  
         
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index and candidates[i]==candidates[i-1])
                continue;
            comb.push_back(candidates[i]);
            if(target-candidates[i]==0)
            {
                result.push_back(comb);
                continue;
            }
            combinationSumUtility(candidates,i+1,target-candidates[i],result,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int>>result;
        vector<int>comb;
        sort(candidates.begin(),candidates.end());
        combinationSumUtility(candidates,0,target,result,comb);
        return result;
    }
};