/*
https://leetcode.com/problems/kth-largest-element-in-a-stream/solution/

TC - O(NlogN + MlogK) - M = no of calls to add
SC - O(N)
Approach
Maintain a min heap of k elements as it will keep the kth largest element at root of min heap
Then it will be O(1) oprtation to get the Kth largest element
*/

class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> minHeap;
    int kth;
    
    /*
    1. Create min heap O(N)
    2. Remove the n-k elements from minheap keeping only k largest elements O(NlogN)
    */
    
    KthLargest(int k, vector<int>& nums)
    {
        kth=k;
        for(int i=0;i<nums.size();i++)
            minHeap.push(nums[i]);
        while(minHeap.size()>kth)
            minHeap.pop();
    }
    
    /*
    1. Push given val to min heap O(logK)
    2. Remove the smallest element as min heap may have k+1 elements O(logK)
    3. Get kth largest element - O(1)
    */
    int add(int val) 
    {
        minHeap.push(val);
        if(minHeap.size()>kth)
            minHeap.pop();
        int kthLargestElem=minHeap.top();
        return kthLargestElem;
        
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
/*
class KthLargest 
{
    priority_queue<int,vector<int>,greater<int>> kmin;
    int k;
public:
    KthLargest(int kth, vector<int>& nums) 
    {
        k=kth;
        for(int a : nums)
        {
            kmin.push(a);
             if(kmin.size()>k)
                kmin.pop();    
        }
    }
    
    int add(int val) 
    {
        kmin.push(val);
        if(kmin.size()>k)
            kmin.pop();
        return kmin.top();
    }
};


*/