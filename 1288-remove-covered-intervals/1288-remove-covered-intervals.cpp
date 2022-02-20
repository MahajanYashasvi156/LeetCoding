/*
Link - https://leetcode.com/problems/remove-covered-intervals/submissions/

TC - O(nlogn)
SC - O(1)
*/
class Solution 
{
    //[[1,2],[1,4],[3,4]] for this example
    static bool comparatorSort(vector<int> &i1,vector<int> &i2)
    {
        if(i1[0]==i2[0]) return i1[1]>i2[1];
        return i1[0]<i2[0];
    }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) 
    {
        sort(intervals.begin(),intervals.end(),comparatorSort);
        int n = intervals.size();
        int l = INT_MAX;
        int r = INT_MIN;
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(intervals[i][0]>=l and r>=intervals[i][1])
            {
                count++;
                continue;
            }
            l= intervals[i][0];
            r = intervals[i][1];
        }
        return n-count;
    }
};


