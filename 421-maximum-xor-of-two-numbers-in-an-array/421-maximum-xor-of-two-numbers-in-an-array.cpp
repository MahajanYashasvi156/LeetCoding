class Trie
{
    Trie* node[2];
    
    public :
    bool containsKey(int bit)
    {
        if(node[bit]==NULL)
            return false;
        return true;
    }
    
    void put(int bit, Trie* newTrie)
    {
        node[bit] = newTrie;
    }
    
    Trie* get(int bit)
    {
        return node[bit];
    }
};
class Solution 
{
    void insert(Trie* root,int n)
    {
        Trie* node = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (n>>i) & 1;

            if(node->containsKey(bit)==false)
            {
                node->put(bit,new Trie());
            }
            node = node->get(bit);
        }
    }
    
    int getMaxXOR(Trie* root,int num)
    {
        int maxXor = 0;
        Trie* node = root;
        
        for(int i = 31;i>=0;i--)
        {
            int bit = num>>i & 1;
            int oppositeBit = bit ^ 1;
            
            if(node->containsKey(oppositeBit))
            {
                node = node->get(oppositeBit);
                maxXor = 1<<i | maxXor;
            }
            else
                node = node->get(bit);
        }
        return maxXor;
    }
public:
    int findMaximumXOR(vector<int>& nums) 
    {
        Trie* root = NULL;
        root = new Trie();
        
        for(int n:nums)
            insert(root,n);
        
        int result = 0;
        for(int n:nums)
        {
            result = max(result,getMaxXOR(root,n));
        }
        
        return result;
    }
};