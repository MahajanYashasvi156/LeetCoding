class Solution 
{
    static bool comp(vector<int>& a, vector<int>&b)
    {
        if(a[0]<b[0])
            return true;
        if(a[0]==b[0] and a[1]>b[1])
            return true;
        return false;
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
         vector<vector<int>> ans(people.size(),vector<int>(2,-1));
        
        sort(people.begin(),people.end(),comp);
        
        for(auto p : people)
        {
            int h = p[0];
            int k = p[1];
            int count = 0;
            for(int i = 0;i<people.size();i++)
            {
                if(ans[i][0]==-1)
                    count++;
                if(count == k+1)
                {
                    ans[i] = p;
                    break;
                }
                    
            }
        }
        return ans;
    }
};