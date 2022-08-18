/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution 
{
    int findPeak(MountainArray &mountainArr) 
    {
        int low = 1;
        int high = mountainArr.length()-2;
        
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            
            int midElement = mountainArr.get(mid);
            int prev = mountainArr.get(mid-1);
            int next = mountainArr.get(mid+1);
            
            if(prev<midElement and next<midElement)
               return mid; 
            
            if(prev<midElement)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int binary_search1(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int midElement = mountainArr.get(mid);
            if(midElement == target)
                return mid;
            if(midElement<target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
    int binary_search2(MountainArray &mountainArr,int low,int high,int target)
    {
        while(low<=high)
        {
            int mid = low+(high-low)/2;
            int midElement = mountainArr.get(mid);
            if(midElement == target)
                return mid;
            if(midElement>target)
                low = mid+1;
            else
                high = mid-1;
        }
        return -1;
    }
public:
    int findInMountainArray(int target, MountainArray &mountainArr) 
    {
        int peakIndex = findPeak(mountainArr);
      
        int ans = binary_search1(mountainArr,0,peakIndex,target);
        if(ans ==-1)
            ans = binary_search2(mountainArr,peakIndex+1,mountainArr.length()-1,target);
        return ans;
    }
};