class Solution 
{
public:
    int largestRectangleArea(vector<int>& A) 
    {
        stack<int> s;
        vector<int> leftSmaller(A.size(),-1);
        vector<int> rightSmaller(A.size(),A.size());

        for(int i = 0;i<A.size();i++)
        {
            while(!s.empty() and A[s.top()]>=A[i])
                s.pop(); 
            if(!s.empty())
                leftSmaller[i] = s.top();
            s.push(i);
        }

        while(!s.empty()) s.pop();

        for(int i = A.size()-1;i>=0;i--)
        {
            while(!s.empty() and A[s.top()]>=A[i])
            {
                s.pop();
            } 
            if(!s.empty())
                rightSmaller[i] = s.top();
            s.push(i);
        }

        int result = 0;
        for(int i = 0;i<A.size();i++)
        {
            result = max(result,(rightSmaller[i]-leftSmaller[i]-1)*A[i]);
        }
        return result;
    }
};






/*

Link - https://leetcode.com/problems/largest-rectangle-in-histogram/
 
TC - O(N)
SC - O(N)
    
Intuition - 

For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively. 
 
Approach - 

We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once. A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar. How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. Following is the complete algorithm.
1) Create an empty stack.
2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1. 
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack. 
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) item in stack and ‘right index’ is ‘i’ (current index).
3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.



class Solution {
public:
 
    int largestRectangleArea(vector<int>& heights) 
    {
        stack<int> s;
        int currLarRecArea=0;
        int leftMin=-1;
        int rightMin=0;
        int i;
        for(i=0;i<heights.size();i++)
        {
            if(s.empty() or heights[s.top()]<=heights[i])
            {
                s.push(i);
            }
            else 
            {
                while(!s.empty() and heights[s.top()]>heights[i])
                {
                    int minbar=heights[s.top()];
                    s.pop();
                    if(s.empty())
                        leftMin=-1;
                    else
                        leftMin=s.top();
                    rightMin=i;
                    currLarRecArea=max(currLarRecArea,(rightMin-leftMin-1)*minbar);  
                    
                }
                s.push(i);
            }
        }
        //when stack is not empty and bars ended.This means for all the bars in the stack right min not exist.
        while(!s.empty())
        {
            int minbar=heights[s.top()];
            s.pop();
            if(s.empty())
                leftMin=-1;
            else
                leftMin=s.top();
            rightMin=i;
            currLarRecArea=max(currLarRecArea,(rightMin-leftMin-1)*minbar);  
                    
       }        
        return currLarRecArea;
    }
};

*/