class Solution {
public:
    string countAndSay(int n) 
    {
        string prev = "1";
        for(int i =1;i<n;i++)
        {
            string temp = prev;
            prev = "";
            for(int j = 0;j<temp.size();j++)
            {
                int count = 1;
                while(j<temp.size()-1 and temp[j]==temp[j+1])
                {
                    count++;
                    j++;
                }
                prev = prev + to_string(count)+temp[j];
            }
        }
        
        return prev;
    }
};