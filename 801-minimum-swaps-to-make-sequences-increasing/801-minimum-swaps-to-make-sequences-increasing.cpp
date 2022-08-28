class Solution {
public:
    int minSwap(vector<int>& nums1, vector<int>& nums2)
    {
        int n = nums1.size();
        
        vector<int> noSwap(n,INT_MAX);
        vector<int> swap(n,INT_MAX);
        
        noSwap[0] = 0;
        swap[0] = 1;
        
        for(int i = 1;i<n;i++)
        {
            if(nums1[i]>nums1[i-1] and nums2[i]>nums2[i-1])
                noSwap[i] = min(noSwap[i],noSwap[i-1]);
            
            if(nums1[i]>nums2[i-1] and nums2[i]>nums1[i-1])
                noSwap[i] = min(noSwap[i],swap[i-1]);
            
            if(nums2[i]>nums1[i-1] and nums1[i]>nums2[i-1])
                swap[i] = min(swap[i],noSwap[i-1]+1);
            
            if(nums2[i]>nums2[i-1] and nums1[i]>nums1[i-1])
                swap[i] = min(swap[i],swap[i-1]+1);
        }
        return min(swap[n-1],noSwap[n-1]);
    }
};