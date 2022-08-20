class Solution 
{
    
    int solve(int index,vector<int>&cookies,vector<int> &distribution)
    {
        if(index==cookies.size())
        {
            return 
        *max_element(distribution.begin(),distribution.end());   
        }
       
        int mini = INT_MAX;
        for(int i = 0;i<distribution.size();i++)
        {
            distribution[i]  = distribution[i] + cookies[index];
            mini = min(mini,solve(index+1,cookies,distribution));
            distribution[i]  = distribution[i] -  cookies[index];
        }
        return mini;
    }
public:
    int distributeCookies(vector<int>& cookies, int k) 
    {
        vector<int> distribution(k,0);
       
        return solve(0,cookies,distribution);   
    }
};