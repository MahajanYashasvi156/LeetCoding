/*
Link - https://leetcode.com/problems/combination-sum-ii/ 

Intution - Same as Subset -II (Without duplicates with given repeating elements)

Paradigm - Iterative.
Time Complexity: O(2^n * k) 
Space Complexity: O(x * k) k is the average length and x is the no. of combinations
*/

class Solution 
{
public:
     void combinationSumUtility(vector<int>& candidates,int index,int target, vector<vector<int>>&result,vector<int>&comb)
    {  
        if(target<0)
            return;  
        if(target==0)
        {
            result.push_back(comb);
            return;
        }
        for(int i=index;i<candidates.size();i++)
        {
            if(i!=index and candidates[i]==candidates[i-1])
                continue;
            
            comb.push_back(candidates[i]);
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

/*
class Solution 
{
public:
     void  generateCombination(int target,int index,vector<int>&A,vector<int>&path,vector<vector<int>>&allCombination)
    {
        if(target<0) return;
        if(target==0) 
        {
            allCombination.push_back(path);
            return;
        }
        if(index>=A.size()) return;

        path.push_back(A[index]);
        generateCombination(target-A[index],index+1,A,path,allCombination);
        path.pop_back();

        while(index<A.size()-1 and A[index]==A[index+1])
        {
            index++;
        }
        generateCombination(target,index+1,A,path,allCombination);
    }
    vector<vector<int>> combinationSum2(vector<int>& A, int target)
    {
        sort(A.begin(),A.end());
        vector<vector<int>>allCombination ;
        vector<int>path;
        generateCombination(target,0,A,path,allCombination);
        return allCombination;
    }
};
*/


