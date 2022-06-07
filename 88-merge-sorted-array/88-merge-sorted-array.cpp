/*
Link - https://leetcode.com/problems/merge-sorted-array/

TC - O(nlogn)
SC - O(1)
*/

/*
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        for(int i=0;i<n;i++)
        {
            nums1[m+i]= nums2[i];
        }
        sort(nums1.begin(),nums1.end());
    }
};
*/

/*
TC - O(m+n)
SC - O(1)

class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;//Last index of nums1 array.
        
        while(i>=0 and j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[k--]=nums1[i--];
            }
            else
                nums1[k--]=nums2[j--];
        }
        
        while(i>=0)
        {
            nums1[k--]=nums1[i--];
        }
        while(j>=0)
        {
            nums1[k--]=nums2[j--];
        }
        
    }
};
*/
class Solution 
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int k = m+n-1;
        int i = m-1;
        int j = n-1;
        while(i>=0 or j>=0)
        {
            int x = i>=0 ? nums1[i]:INT_MIN;
            int y = j>=0 ? nums2[j]:INT_MIN;
            
            if(x<=y)
            {
                nums1[k--] = y;
                j--;
            }
            else
            {
                nums1[k--] = x;
                i--;
            }
        }
    }
};