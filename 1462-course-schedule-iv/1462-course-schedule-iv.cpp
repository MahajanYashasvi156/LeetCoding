/*
Link - https://leetcode.com/problems/course-schedule-iv/

TC - O(N^3 + Q)
SC - O(N^2)

Floyd Warshall Algo - All pair shortest path
*/

class Solution 
{
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) 
    {
        vector<vector<int>> mat(numCourses,vector<int>(numCourses,INT_MAX));
        
        for(int i=0;i<numCourses;i++)
            mat[i][i]=0;
        
        for(int i=0;i<prerequisites.size();i++)
        {
            int start = prerequisites[i][0];
            int end = prerequisites[i][1];
            
            mat[start][end]=1;
        }
        
        for(int k=0;k<numCourses;k++)
        {
            for(int i = 0;i<numCourses;i++)
            {
                for(int j=0;j<numCourses;j++)
                    if(mat[i][k]!=INT_MAX and mat[k][j]!=INT_MAX)
                        mat[i][j]=min(mat[i][j], mat[i][k]+mat[k][j]);
            }
        }
        
        vector<bool> result;
        for(int i=0;i<queries.size();i++)
        {
            int preCourse = queries[i][0];
            int postCourse = queries[i][1];
            
            if(mat[preCourse][postCourse]!=INT_MAX)
                result.push_back(true);
            else 
                result.push_back(false);
        }
        return result;
    }
};