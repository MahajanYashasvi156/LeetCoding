class Node
{
    Node* node[2];
    public:
        bool containsKey(int bit)
        {
            if(node[bit]==NULL)
                return false;
            return true;
        }
        void putKey(int bit,Node* newNode)
        {
            node[bit] = newNode;
        }
        Node* getKey(int bit)
        {
            return node[bit];
        }
};
class Trie
{
    Node* root = NULL;
    public:
        Trie()
        {
            root = new Node();
        }
    
        void insert(int n)
        {
            Node* node = root;

            for(int i = 31;i>=0;i--)
            {
                int bit = (n>>i) & 1;

                if(node->containsKey(bit)==false)
                    node->putKey(bit,new Node());

                node = node->getKey(bit);
            }
        }
    
        int getMaxXor(int n)
        {
            //If there exist no element smaller than bound then trie will be emepty so return -1.
            if(root->containsKey(1)==false and root->containsKey(0)==false)
                return -1;
            int ans = 0;
            Node* node = root;
            for(int i = 31;i>=0;i--)
            {
                int bit = n>>i & 1;
                
                int oppositeBit = bit ^ 1;
                
                if(node->containsKey(oppositeBit))
                {
                    ans = ans | 1<<i;
                    node = node->getKey(oppositeBit);
                }
                else
                    node = node->getKey(bit);
            }
            return ans;
        }
};
class Solution 
{
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) 
    {
        sort(nums.begin(),nums.end());
        vector<pair<int,pair<int,int>>> queryIndex ;
        
        for(int i = 0;i<queries.size();i++)
        {
            queryIndex.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(queryIndex.begin(),queryIndex.end());
        
        vector<int> result(queries.size());
        Trie* root = new Trie();
        int i = 0;
        for(auto q: queryIndex)
        {
            int maxBound = q.first;
            int x = q.second.first;
            int index = q.second.second;
            
            while(i<nums.size() and nums[i]<=maxBound)
            {
                root->insert(nums[i]);
                i++;
            }
            result[index] = root->getMaxXor(x);
            
        }
        return result;
    }
};