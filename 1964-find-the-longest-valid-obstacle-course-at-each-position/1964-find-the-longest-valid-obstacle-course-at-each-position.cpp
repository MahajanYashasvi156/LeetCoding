class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) 
    {
        vector<int> LIS;
        vector<int> ans;
        
        for(int i = 0;i<obstacles.size();i++)
        {
            int index = upper_bound(LIS.begin(),LIS.end(),obstacles[i]) - LIS.begin();
            
            if(index==LIS.size())
                LIS.push_back(obstacles[i]);
            else
                LIS[index] = obstacles[i];
            ans.push_back(index+1);
        }
        return ans;
    }
};