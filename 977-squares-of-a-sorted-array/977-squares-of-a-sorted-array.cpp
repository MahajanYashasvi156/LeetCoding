class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) 
    {
        int i =0;
        while(i<A.size() and A[i]<0)
        {
            i++;
        }
        int middle = i;
        reverse(A.begin(),A.begin()+middle);
        int f = 0;
        int fend = middle;
        int s = middle;
        int ssend = A.size();
        vector<int> result ;
        while(f<fend and s<ssend)
        {
            if(abs(A[f])<=A[s])
            {
                result.push_back(A[f]*A[f]);
                f++;
            }
            else
            {
                result.push_back(A[s]*A[s]);
                s++;
            }
        }
        while(f<fend)
        {
           result.push_back(A[f]*A[f]);
            f++;
        }
        while(s<ssend)
        {
           result.push_back(A[s]*A[s]);
            s++;
        }

        return result;
    }
};

/*
class Solution 
{
public:
    vector<int> sortedSquares(vector<int>& A) {
        int freq[10001] ={0};
    for(int i =0;i<A.size();i++)
    {
        freq[abs(A[i])]++;
    }
    vector<int>result;
    for(int i =0;i<10001; i++)
    {
        while(freq[i]>0)
        {
            result.push_back(i*i);
            freq[i]--;
        }
    }
    return result;
    }
};
*/