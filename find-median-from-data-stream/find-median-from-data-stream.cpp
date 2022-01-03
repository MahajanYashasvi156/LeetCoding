class MedianFinder 
{
public:
    priority_queue<int> firstHalfMaxHeap;
    priority_queue<int,vector<int>,greater<int>> secondHalfMinHeap;
    
    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        if(firstHalfMaxHeap.size()==0)
            firstHalfMaxHeap.push(num);
        else if(firstHalfMaxHeap.size()==secondHalfMinHeap.size())
        {
            int ele = secondHalfMinHeap.top();
            if(ele >= num)
            {
                firstHalfMaxHeap.push(num);
            }
            else
            {
                secondHalfMinHeap.pop();
                secondHalfMinHeap.push(num);
                firstHalfMaxHeap.push(ele);
            }
        }
        
        else
        {
            int ele = firstHalfMaxHeap.top();
            if(ele <= num)
            {
                secondHalfMinHeap.push(num);
            }
            else
            {
                firstHalfMaxHeap.pop();
                firstHalfMaxHeap.push(num);
                secondHalfMinHeap.push(ele);
            }
            
        }
    }
    
    double findMedian() 
    {
        //even - (max of maxheap+min of minheap)/2
        if((secondHalfMinHeap.size()+firstHalfMaxHeap.size())%2==0)
            return (secondHalfMinHeap.top()+firstHalfMaxHeap.top())/2.0;
        return firstHalfMaxHeap.top();
            
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */