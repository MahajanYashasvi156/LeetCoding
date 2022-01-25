
/*
Link - https://leetcode.com/problems/valid-mountain-array/submissions/

TC - O(N)
SC - O(1)

Peak element cant be starting or ending element.
Before peak element all elements should in increasing order.
After peak element all elememts should be in decreasing order.
*/
class Solution 
{
public:
    bool validMountainArray(vector<int>& arr)
    {
       int n = arr.size();
        int i=0;
        while(i+1<n and arr[i]<arr[i+1])
        {
            i++;
        }
        if(i==0 or i==n-1)
            return false;
        while(i+1<n and arr[i]>arr[i+1])
        {
            i++;
        }
        if(i!=n-1)
            return false;
        return true;
    
    }
};