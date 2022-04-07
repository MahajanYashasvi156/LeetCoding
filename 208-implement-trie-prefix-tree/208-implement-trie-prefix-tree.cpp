struct Node
{
    Node *links[26];
    bool flag = false;
    
    bool containsKey(char c)
    {
        if(links[c-'a']!=NULL)
            return true;
        return false;
    }
    
    void put(char c, Node *node)
    {
        links[c-'a'] = node;
    }
    
    Node* set(char c)
    {
        return links[c-'a'];
    }
};
class Trie 
{
    Node *root;
public:
    Trie() 
    {
        root = new Node();   
    }
    
    void insert(string word) 
    {
        Node * node = root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i])==false)
            {
                node->put(word[i],new Node());
            }
            node = node->set(word[i]);
        }
        
        node->flag = true;
    }
    
    bool search(string word) 
    {
        Node * node = root;
        for(int i=0;i<word.length();i++)
        {
            if(node->containsKey(word[i])==false)
            {
               return false;
            }
            node = node->set(word[i]);
        }
        
        return node->flag;
        
    }
    
    bool startsWith(string prefix) 
    {
        Node * node = root;
        for(int i=0;i<prefix.length();i++)
        {
            if(node->containsKey(prefix[i])==false)
            {
               return false;
            }
            node = node->set(prefix[i]);
        }
        
        return true;    
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */