/*

    Since both arrays are in decreasing order. 
    
    if a number in nums2 is greater for ith index of nums1 and then it will be greater for all number after ith index in nums1 as those numbers are smaller than ith element. So we don't need to start our traversal in second array from start for each element of nums1. We can just start from where the previous element of nums1 ended.
    
    TC = O(m+n)
*/
class Solution 
{
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int ans = 0;
        
        int j = 0;
        
        for(int i = 0;i<nums1.size();i++)
        {
            
            while(j<nums2.size() and nums1[i]<=nums2[j])
            {
                j++;
            }
            
            ans = max(ans , j-i-1);
        }
        return ans;
    }
};


//upper_bound in case of reverse sorted works diffrent. It will find the first smaller number in the array.

//Here we want the number which greater than equal to so we use upper bound which will return iterator of first smaller number, just the previous number is our farthest greater or equal number

//TC = O(nlogm)
/*
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) 
    {
        int ans = 0;
        
        for(int i = 0;i<nums1.size();i++)
        {
            int j = upper_bound(nums2.begin()+i,nums2.end(),nums1[i],greater<int>())-nums2.begin()-1 ;
            
            ans = max(ans,j-i);
        }
        return ans;
    }
};
*/