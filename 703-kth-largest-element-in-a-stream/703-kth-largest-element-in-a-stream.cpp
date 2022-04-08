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

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */