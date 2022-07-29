class Solution 
{
    int findParent(int x,vector<int>&parent)
    {
        if(parent[x]==x)
            return x;
        return parent[x] = findParent(parent[x],parent);
    }
    
    void unionFind(int x,int y ,vector<int>&parent)
    {
        int absoluteParentX = findParent(x,parent);
        int absoluteParentY = findParent(y,parent);
        
        if(absoluteParentX!=absoluteParentY)
        {
            parent[absoluteParentX] = absoluteParentY;
        }
    }
public:
    int largestComponentSize(vector<int>& nums) 
    {
        //create a parent array of maximum element size.
        int n = *max_element(nums.begin(),nums.end());
        vector<int> parent(n+1,-1);
        //Initially all elements are individual components.
        for(int i = 0;i<=n;i++)
            parent[i] = i;
        
        //For each number find the factors and connect them as a single compoent.
        for(int num : nums)
        {
            for(int j = 2;j*j<=num;j++)
            {
                if(num%j==0)
                {
                    unionFind(num,j,parent);
                    unionFind(num,num/j,parent);
                }
                
            }
        }
        int ans = 0;
        unordered_map<int,int> freq;
        for(int i = 0;i<nums.size();i++)
        {
            freq[findParent(nums[i],parent)]++;
            ans = max(ans,freq[findParent(nums[i],parent)]);
        }
        return ans;
    }
};