//upper_bound in case of reverse sorted works diffrent. It will find the first smaller number in the array.

//Here we want the number which greater than equal to so we use upper bound which will return iterator of first smaller number, just the previous number is our farthest greater or equal number

//TC = O(nlogm)

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