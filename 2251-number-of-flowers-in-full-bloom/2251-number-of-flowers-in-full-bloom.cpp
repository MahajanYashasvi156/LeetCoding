class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) 
    {
        vector<int> start;
        vector<int> stop;
        
        for(auto a:flowers)
        {
            start.push_back(a[0]);
            stop.push_back(a[1]);
        }
        
        sort(start.begin(),start.end());
        sort(stop.begin(),stop.end());
        
        vector<int> result(persons.size());
        
        for(int i = 0;i<persons.size();i++)
        {
            int startedBlooming = upper_bound(start.begin(),start.end(),persons[i]) - start.begin();
            
            int stoppedBlomming =  lower_bound(stop.begin(),stop.end(),persons[i]) - stop.begin();
            
            result[i] = startedBlooming-stoppedBlomming;
        }
        return result;
    }
};