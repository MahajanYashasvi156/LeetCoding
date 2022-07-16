/*
Intuition - Try to pick the number which allows to make as many 1's from the left side(MSB).

32 31 30 ______ 3 2 1

we try to make 1 on the 32th bit, if not possible then we are bound to pick elements which can make 0 at 32th bit of the maximum xor result. 
we try to make 1 on the 31th bit, and so on.
*/
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
        //All elements will start from the root node.
        Trie* node = root;
        for(int i = 31;i>=0;i--)
        {
            int bit = (n>>i) & 1;

            if(node->containsKey(bit)==false)
                node->put(bit,new Trie());
        
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
            
            //If opposite bit present in the current refrence trie then the xor bit will be 1.
            if(node->containsKey(oppositeBit))
            {
                node = node->get(oppositeBit);
                maxXor = 1<<i | maxXor;
            }
            //If opposite bit not present then the current xor bit of maxXor will not be set and we are bound to go with the number with the same bit only.
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
        
        //Insert all the elements in the Trie in 32- bits.
        for(int n:nums)
            insert(root,n);
        
        int result = 0;
        //Find the max xor of an element with all elements of the array.
        for(int n:nums)
            result = max(result,getMaxXOR(root,n));
        
        return result;
    }
};