//Link - https://leetcode.com/problems/combination-sum/


/* 
 0ms

Paradigm - Recursive - Same as Subset- 1

Time Complexity: O(2^t * k) where t is the target, k is the average length
Space Complexity: O(k*x), k is the average length and x is the no. of combinations
AS - O(t)

Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)

Why not (2^n) but (2^t) (where n is the size of an array)?

Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.



Here No need to handle the case of duplicates as all candidates are unique and there is no chance of duplicate subset.

*/
/*
class Solution 
{
public:
    void combinationSumUtility(vector<int>& candidates,int index,int target, vector<vector<int>>&result,vector<int>&path)
    {
        if(target<0 or index==candidates.size())
            return;
        
        if(target==0)
        {
            result.push_back(comb);
            return;
        }
        path.push_back(candidates[index]);
        combinationSumUtility(candidates,index,target-candidates[index],result,path);
        path.pop_back();
        combinationSumUtility(candidates,index+1,target,result,path);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int>>result;
        vector<int>path;
        combinationSumUtility(candidates,0,target,result,path);
        return result;
    }
};
*/
/*
Time Complexity: O(2^t * k) 
Space Complexity: O(x * k) k is the average length and x is the no. of combinations
AS - O(t)
Intution - almost same as subset-II

Here, the catch is we can take any element from the set infinite number of times. So for that if we can't simply make decision for particular element and go ahead. 
We have to stay at that index untill we are sure that if we take this particular element infintely it will never give us the target sum (ensured by target<0) or we get the target then also increment the index and try for other combination by incrementing the index.

For Example s={1,2,3} target=3

Initial Call - call(target=3,index=0)

Loop : i=0,1,2

i=0 - call(target=3,index=0) -> call(target=2,index=0) -> call(target=1,index=0)->call(target=0,index=0) add to the result and backtrack to call(target=1,index=0) .Now this will call to call(target=1,index=1)->call(target=-1,index=1) return and backtrack to call(target=2,index=0). Now this will call to call(target=2,index=1)-> call(target=0,index=1) add to the result and backtrack to call(target=3,index=0). Now i will be incremented to 1.
Result-<<1,1,1>,<1,2>>

i=1 - call(target=1,index=1)->call(target=-1, index=1) return and backtrack to call(target=1,index=1). Now this will call to call(target=-1,index=2) return and backtrack to call call(target=1,index=1). Now i will be incremented to 2.
Result-<<1,1,1>,<1,2>>

i=2 - call(target=0,index=2) continue and then loop terminates.
Result-<<1,1,1>,<1,2>,<3>>

*/
class Solution 
{
public:
     void combinationSumUtility(vector<int>& candidates,int index,int target, vector<vector<int>>&result,vector<int>comb)
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
            comb.push_back(candidates[i]);
            combinationSumUtility(candidates,i,target-candidates[i],result,comb);
            comb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>>result;
        vector<int>comb;
        sort(candidates.begin(),candidates.end());
        combinationSumUtility(candidates,0,target,result,comb);
        return result;
    }
};
