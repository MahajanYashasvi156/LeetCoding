class Node
{
    public:
        Node *links[26];
        bool flag = false;
};

class WordDictionary 
{
    Node *root;
public:
    WordDictionary() 
    {
        root = new Node();
    }
    bool searchWord(Node* node,string word,int i) 
    {
        if(i==word.size())
            return node->flag;
        
        if(word[i]!='.')
        {
            if(node->links[word[i]-'a']==NULL)
            {
                return false;
            }
            node = node->links[word[i]-'a'];
            return searchWord(node,word,i+1);
        }
        else
        {
            for(char ch = 'a';ch<='z';ch++)
            {
                if(node->links[ch-'a'])
                {
                    if(searchWord(node->links[ch-'a'],word,i+1))
                        return true;
                }
                
            }
            return false;
        }
        return false; 
    }
    
    void addWord(string word) 
    {
        Node *node = root;
        for(char c : word)
        {
            if(node->links[c-'a']==NULL)
            {
                node->links[c-'a']=new Node();;
            }
            node = node->links[c-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word) 
    {
        return searchWord(root,word,0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */