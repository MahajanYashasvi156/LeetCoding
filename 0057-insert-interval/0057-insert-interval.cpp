class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;
    result.push_back(newInterval);
    for(int i=0;i<intervals.size();i++)
    {
        int lastResult = result.size()-1;

        vector<int> lastInterval = result[lastResult];
        vector<int>  currentInterval = intervals[i];

        if(lastInterval[0]>currentInterval[1])
        {
            result[lastResult] = currentInterval;
             result.push_back(lastInterval);

        }
        else if(currentInterval[0]>lastInterval[1])
        {
            result.push_back(currentInterval);
        }
        else  //overlapping case
        {
           int  minStart = min(currentInterval[0],lastInterval[0]);
           int  maxEnd  = max(currentInterval[1],lastInterval[1]);
            result[lastResult]={minStart,maxEnd};
        }
    }
    return result;
    }
};