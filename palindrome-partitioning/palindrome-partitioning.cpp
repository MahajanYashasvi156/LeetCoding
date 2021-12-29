class Solution
{
    public:
    //To Check if given string is palindrome or not.
    bool isPalindrome(string s)
    {
        int i=0;
        int j=s.size()-1;
        while(i<j)
        {
            if(s[i]!=s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void partitionUtility(string s, int index,vector<string> singlePartition, vector<vector<string>> &palPartition )
    {
        if(index==s.size())
        {
            palPartition.push_back(singlePartition);
            return;
        }
        
        for(int i=index;i<s.size();i++)
        {
            cout<<i<<" ";
            if(isPalindrome(s.substr(index,i+1-index)))
            {
                cout<<s.substr(index,i+1-index)<<endl;
                singlePartition.push_back(s.substr(index,i+1-index));
                partitionUtility(s,i+1,singlePartition,palPartition);
                singlePartition.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>>palPartition;
        vector<string> singlePartition;
        partitionUtility(s,0,singlePartition,palPartition);
        return palPartition;
    }
};