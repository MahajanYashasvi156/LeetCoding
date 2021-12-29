
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

/*
Time Complexity: O(2^n) 
Space Complexity: O(2^n * k)

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


class Solution 
{
public:
     void combinationSumUtility(vector<int>& candidates,int index,int target, vector<vector<int>>&result,vector<int>comb)
    {  
        if(target<0)
            return;  
         
        for(int i=index;i<candidates.size();i++)
        {
            comb.push_back(candidates[i]);
            if(target-candidates[i]==0)
            {
                result.push_back(comb);
                continue;
            }
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
*/