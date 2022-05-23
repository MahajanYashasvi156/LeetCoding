/*
class Solution {
public:
    int findDuplicate(vector<int>& A) 
    {
        vector<int>count(A.size(),0);
        for(int i =0;i<A.size();i++)
        {
            count[A[i]]++;
            if(count[A[i]]>1)
                return A[i];
        }
        return -1;
    }
};
*/
// As there is duplicate element, thus cycle present
// Thus, this problem boils down to cycle detection of list
// We are solving this using Tortoise method

class Solution {
public:
    int findDuplicate(vector<int>& A) 
    {
        int slow = A[0];
        int fast  = A[0];
        do
        {
            slow = A[slow];
            fast = A[A[fast]];
        }while(slow!=fast);
        fast= A[0];
        while(slow!=fast)
        {
            slow = A[slow];
            fast = A[fast];
        }
        return slow;
    }
};