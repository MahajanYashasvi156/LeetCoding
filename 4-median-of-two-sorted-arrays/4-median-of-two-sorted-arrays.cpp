class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        if(nums2.size()<nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int leftElem=( nums1.size()+nums2.size()+1)/2;
        
        int low=0;
        int high=nums1.size();
        
        int part1;
        int part2;
        int left1;
        int left2;
        int right1;
        int right2;
        
        while(low<=high)
        {
            part1=(low+high)/2;
            part2=leftElem-part1;
            
            if(part1==0)
                left1=INT_MIN;
            else
                left1=nums1[part1-1];
            if(part2==0)
                left2=INT_MIN;
            else
                left2=nums2[part2-1];
            
            if(part1==nums1.size())
                right1=INT_MAX;
            else
                right1=nums1[part1];
            
            if(part2==nums2.size())
                right2=INT_MAX;
            else
                right2=nums2[part2];
            
            if(left1<= right2 and left2 <=right1)
            {
                if((nums1.size()+nums2.size())%2==0)
                    return (max(left1,left2)+min(right1,right2))/2.0;
                else
                    return max(left1,left2);
            
            }
            else if (left1>right2)
                 high=part1-1;
            
            else 
                low=part1+1;
        }
                
        
       return -1;
    }
};