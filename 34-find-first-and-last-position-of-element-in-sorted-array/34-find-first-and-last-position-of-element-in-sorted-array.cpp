class Solution {
public:
    vector<int> searchRange(vector<int>& A, int B) 
    {
        int low = 0;
        int high = A.size()-1;
    
        vector<int> result(2,-1);

        //searching first occurence
        while(low<=high)
        {
            int mid = low+(high - low)/2;
            if(A[mid] == B)
            {
                result[0] = mid ;
                //we found element, but we want first occurence, so we are going left
                high = mid-1;
            }
            else if(A[mid]>B)
            {
                high = mid-1;
            }
            else 
            {
                low = mid+1;
            }
        }
        if(result[0] == -1)
            return result;
        low = result[0];
        high = A.size()-1;

        //searching last occurence
        while(low<=high)
        {
            int mid = low+(high - low)/2;
            if(A[mid] == B)
            {
                result[1] = mid;
                //we found element, but we want last occurence, so we are going right
                low = mid+1;
            }
            else if(A[mid]>B)
            {
                high = mid-1;  
            }
            else 
            {
                low = mid+1;
            }
        }
        return result;  
    }
};