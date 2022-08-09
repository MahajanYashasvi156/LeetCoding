class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> res;
        vector<int> ans;
        
        for(int i = 0;i<obstacles.size();i++)
        {
            auto it = upper_bound(res.begin(),res.end(),obstacles[i]) - res.begin();
            
            if(it==res.size())
                res.push_back(obstacles[i]);
            else
                res[it] = obstacles[i];
            ans.push_back(it+1);
        }
        return ans;
    }
};