class Solution {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) 
    {
            int m = A.size();
            int n = B.size();

            int required = (m+n+1)/2; 

            int low = 0 ;
            int high = A.size();

            while(low<=high)
            {
                int i = low+(high-low)/2;
                int j = required-i;

                if(j>n)
                {
                    low = i+1;
                    continue;
                }
                else if(j<0)
                {
                    high = i-1;
                    continue;
                }

                int left1 = INT_MIN;
                int left2 = INT_MIN;
                int right1 = INT_MAX;
                int right2 = INT_MAX;

                if(i>0)
                    left1 = A[i-1];
                if(j>0)
                    left2 = B[j-1];
                if(i<m)
                    right1 = A[i];
                if(j<n)
                    right2 = B[j];

                if(left1<=right2 and left2<=right1)
                {
                    if((m+n)%2 == 0)
                    {
                        return (max(left1,left2)+min(right1,right2))/2.0;
                    }
                    else //left extra one
                    {
                        return max(left1,left2)/1.0;
                    }

                }
                else if(left1>right2)
                {
                    high = i - 1;
                }
                else
                {
                    low = i+1;
                }
            }
          return 0;
    }
};