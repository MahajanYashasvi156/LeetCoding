class Solution 
{
    void generateCombination(int index,vector<int>&num,int k,int n,vector<int>&path,vector<vector<int>>&allCombination)
    {
        if(n==0)
        {
            if(k==0)
                allCombination.push_back(path);
            return;
        }
        if(index==num.size() || n<0 || k==0) return;
        
        for(int i = index;i<num.size();i++)
        {
            path.push_back(num[i]);
            generateCombination(i+1,num,k-1,n-num[i],path,allCombination);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) 
    {
        vector<int> num(9);
        for(int i = 1;i<=9;i++) num[i-1] = i;
        
        vector<vector<int>>allCombination;
        vector<int>path;
        generateCombination(0,num,k,n,path,allCombination);
        return allCombination;
        
    }
};