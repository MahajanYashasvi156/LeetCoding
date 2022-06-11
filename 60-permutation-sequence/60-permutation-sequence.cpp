class Solution 
{
public:
    string getPermutation(int n, int k) 
    {
        int fact = 1;
        vector<int> num;
        for(int i = 1;i<n;i++)
        {
            fact*=i;
            num.push_back(i);
        }
        num.push_back(n);
        k = k-1;
        string kthpermut = "";

        while(true)
        {
            int i = k/fact;
            kthpermut = kthpermut+to_string(num[i]);
            num.erase(num.begin()+i);
            if(num.size()==0)
                break;
            k = k%fact;
            fact=fact/(num.size());
        }
        return kthpermut;
    }
};