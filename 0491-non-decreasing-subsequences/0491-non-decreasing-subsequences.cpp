class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums)
    {
        set<vector<int>> s;
        
        vector<vector<vector<int>>> temp(nums.size());
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                if(nums[j]<=nums[i])
                {
                    temp[i].push_back({nums[j],nums[i]});
                    s.insert({nums[j],nums[i]});
                    for(auto a:temp[j])
                        {
                            vector<int>t(a);
                            t.push_back(nums[i]);
                            temp[i].push_back(t);
                            s.insert(t);
                        }
                }
                
            }
        }
        return {s.begin(),s.end()};
    }
};